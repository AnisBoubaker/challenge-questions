import os
import json
import openai
from dotenv import load_dotenv
from langchain_openai import OpenAIEmbeddings
from langchain_chroma import Chroma
from langchain.schema import Document

# Load environment variables from the .env file
load_dotenv()

# Retrieve the OpenAI API key from the .env file
openai.api_key = os.getenv("OPENAI_API_KEY")

# Initialize the OpenAI Embeddings model using Langchain
embeddings = OpenAIEmbeddings(model="text-embedding-3-large")

# Initialize the Chroma vector store with persistence
def initialize_chroma(persist_directory="chroma_store"):
    return Chroma(embedding_function=embeddings, persist_directory=persist_directory)

# Function to generate embeddings and store in ChromaDB (if enabled)
def generate_embeddings(function_ast, generate_embedding_flag=True):
    if generate_embedding_flag:
        # Ensure function_ast is a string before generating embeddings
        if isinstance(function_ast, list):
            function_ast = " ".join(map(str, function_ast))  # Convert list to a space-separated string
        elif not isinstance(function_ast, str):
            function_ast = str(function_ast)  # Convert other types to string

        return function_ast  # Pass the string AST directly if we're letting ChromaDB handle embeddings
    return None  # If embeddings are not required, return None

# Function to find closest matches using ChromaDB with internal embedding computation
def find_similar_functions(function_ast, chroma_store, top_k=5):
    # Perform similarity search based on the AST string directly (embedding is generated internally)
    results = chroma_store.similarity_search_with_score(function_ast, k=top_k)
    similar_functions = []
    
    for result, distance in results:  # Unpack (Document, distance) tuple
        similar_functions.append({
            "distance": distance,  # Store the distance
            "project_name": result.metadata["project_name"],
            "function_name": result.metadata["function_name"],
            "function_code": result.metadata["function_code"]
        })

    # Sort by similarity (ascending order)
    return sorted(similar_functions, key=lambda x: x["distance"])

# Function to process each JSON file and find similar code
def process_json_file(input_file, output_folder, chroma_store, generate_embedding_flag=True):
    with open(input_file, 'r') as f:
        data = json.load(f)

    project_name = data["project_name"]
    functions = data["functions"]

    # Process each function in the JSON file
    for function in functions:
        function_name = function['function_name']
        function_code = function['function_code']
        function_ast = function['function_ast']

        # Step 1: Generate or process function_ast as needed
        function_ast_processed = generate_embeddings(function_ast, generate_embedding_flag)

        # Step 2: Find the closest matches from ChromaDB using internal embedding generation
        if function_ast_processed is not None:
            similar_functions = find_similar_functions(function_ast_processed, chroma_store)
            function["similar_code"] = similar_functions

    # Step 3: Write the updated JSON to the output folder
    output_file = os.path.join(output_folder, os.path.basename(input_file))
    with open(output_file, 'w') as f_out:
        json.dump(data, f_out, indent=4)

# Function to iterate over a folder and process each JSON file
def process_json_folder(input_folder, output_folder, chroma_store, generate_embedding_flag=True):
    # Ensure output directory exists
    os.makedirs(output_folder, exist_ok=True)

    # Iterate through all files in the input folder
    for filename in os.listdir(input_folder):
        if filename.endswith(".json"):
            file_path = os.path.join(input_folder, filename)
            print(f"Processing {file_path}...")
            process_json_file(file_path, output_folder, chroma_store, generate_embedding_flag)

# Initialize the ChromaDB store with persistence
persist_dir = "path/to/persistent_chroma_store"  # Set your preferred directory
chroma_store = initialize_chroma(persist_directory=persist_dir)

# Initialize the ChromaDB store with persistence
persist_dir = "../chromadb"  # Set your preferred directory
chroma_store = initialize_chroma(persist_directory=persist_dir)

# Folder paths
input_folder_path = "../data_ast"
output_folder_path = "../data_scores"

# Set whether to generate embeddings or skip (toggle this variable)
generate_embedding_flag = True  # Set to False if you don't want to recompute embeddings

# Process all JSON files in the input folder and store results in the output folder
process_json_folder(input_folder_path, output_folder_path, chroma_store, generate_embedding_flag)

print("All data has been processed and stored in the output folder.")
