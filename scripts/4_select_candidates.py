import os
import json

# Define paths
input_folder = "../data_scores"
output_folder = "../data_candidates"

# Ensure output folder exists
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# Function to process each JSON file
def process_json_file(file_path, output_folder):
    # Load JSON file
    with open(file_path, "r") as f:
        data = json.load(f)

    # Extract functions and sort by the lowest distance score of the similar_code list
    functions = data["functions"]
    functions_sorted = sorted(functions, key=lambda fn: min(sc["distance"] for sc in fn["similar_code"]), reverse=True)

    # Select the top 6 functions
    selected_functions = functions_sorted[:6]

    # Create new data to save
    new_data = {
        "project_name": data["project_name"],
        "functions": selected_functions
    }

    # Save the result to the new output folder
    output_file_path = os.path.join(output_folder, os.path.basename(file_path))
    with open(output_file_path, "w") as f:
        json.dump(new_data, f, indent=4)

# Process all JSON files in the input folder
for filename in os.listdir(input_folder):
    if filename.endswith(".json"):
        process_json_file(os.path.join(input_folder, filename), output_folder)

print("Processing complete.")
