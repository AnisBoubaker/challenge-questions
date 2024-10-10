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

# Function to generate embeddings and store in ChromaDB
def store_functions_in_chroma(json_file, chroma_store):
    # Load the JSON data
    with open(json_file, 'r') as f:
        data = json.load(f)

    project_name = data["project_name"]
    functions = data["functions"]

    # Create a list to store documents (embedding + metadata)
    documents = []

    for function in functions:
        function_name = function['function_name']
        function_ast = function['function_ast']
        function_code = function['function_code']

        # Prepare metadata for storage
        metadata = {
            "project_name": project_name,
            "function_name": function_name,
            "function_code": function_code
        }

        # Create a Document object with the function AST and metadata
        doc = Document(page_content=function_ast, metadata=metadata)

        # Add the document to the list
        documents.append(doc)

    # Add the documents to ChromaDB
    chroma_store.add_documents(documents)

# Function to iterate over a folder and process each JSON file
def process_json_folder(folder_path, chroma_store):
    # Iterate through all files in the folder
    for filename in os.listdir(folder_path):
        if filename.endswith(".json"):
            file_path = os.path.join(folder_path, filename)
            print(f"Processing {file_path}...")
            store_functions_in_chroma(file_path, chroma_store)

# Initialize the ChromaDB store with persistence
persist_dir = "../chromadb"  # Set your preferred directory
chroma_store = initialize_chroma(persist_directory=persist_dir)

# Folder containing the JSON files
json_folder_path = "../corpus_ast"

# Process all JSON files in the folder
process_json_folder(json_folder_path, chroma_store)

print("All data has been stored in ChromaDB and persisted to disk.")
