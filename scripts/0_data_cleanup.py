import os
import shutil
import re

def remove_comments_from_code(file_content: str) -> str:
    # Remove block comments (/* ... */) and inline comments (// ...)
    # But make sure not to remove preprocessor directives
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " "  # Replace comments with a space to maintain code structure
        else:
            return s

    # This regex removes comments while ignoring preprocessor directives like #include
    pattern = re.compile(
        r"""
        (//.*?$)              | # Match inline comments
        (/\*.*?\*/)|          # Match block comments
        ("(?:\\.|[^\\"])*")|  # Match string literals (to skip over them)
        ('(?:\\.|[^\\'])*')   # Match character literals (to skip over them)
        """, 
        re.VERBOSE | re.DOTALL | re.MULTILINE
    )

    return re.sub(pattern, replacer, file_content)

def read_file_with_fallback(file_path: str) -> str:
    encodings = ['utf-8', 'latin-1', 'iso-8859-1']
    for encoding in encodings:
        try:
            with open(file_path, 'r', encoding=encoding) as file:
                return file.read()
        except UnicodeDecodeError:
            continue
    raise UnicodeDecodeError(f"Cannot decode file {file_path} with available encodings.")

def process_file(file_path: str, output_path: str):
    content = read_file_with_fallback(file_path)
    cleaned_content = remove_comments_from_code(content)
    with open(output_path, 'w', encoding='utf-8') as file:
        file.write(cleaned_content)

def process_directory(input_dir: str, output_dir: str):
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    os.makedirs(output_dir)

    for root, dirs, files in os.walk(input_dir):
        relative_path = os.path.relpath(root, input_dir)
        output_root = os.path.join(output_dir, relative_path)
        os.makedirs(output_root, exist_ok=True)

        for file in files:
            if file.endswith(('.c', '.h', '.cpp', '.hpp')):
                input_file_path = os.path.join(root, file)
                output_file_path = os.path.join(output_root, file)
                process_file(input_file_path, output_file_path)

if __name__ == "__main__":
    input_directory = "../corpus/"
    output_directory = "../corpus_clean/"

    process_directory(input_directory, output_directory)
    print(f"Processing complete. Cleaned files saved in '{output_directory}'.")
