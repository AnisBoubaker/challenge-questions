import subprocess
import os
import re
import json
from pycparser import c_parser, c_ast
from pycparser.plyparser import ParseError  # Import ParseError to handle parser exceptions

class TypedefRemover(c_ast.NodeVisitor):
    def visit_FileAST(self, node):
        new_decls = []
        for decl in node.ext:
            if not isinstance(decl, c_ast.Typedef):
                new_decls.append(decl)
        node.ext = new_decls

class FunctionVisitor(c_ast.NodeVisitor):
    def __init__(self):
        self.functions = []

    def visit_FuncDef(self, node):
        self.functions.append(node)

def concatenate_files(source_dir: str, output_file: str):
    with open(output_file, 'w') as outfile:
        for root, dirs, files in os.walk(source_dir):
            for file in files:
                if file.endswith('.c') or file.endswith('.h'):
                    file_path = os.path.join(root, file)
                    with open(file_path, 'r') as infile:
                        outfile.write(infile.read())
                        outfile.write('\n')

def preprocess_c_file(input_file: str, output_file: str = "preprocessed.c", include_dirs=None):
    if include_dirs is None:
        include_dirs = []

    if not os.path.isfile(input_file):
        raise FileNotFoundError(f"The input file '{input_file}' does not exist.")

    fake_libc_include = '/Users/anis/Sync/01_ETS/Dev/challenge-questions/lib/python3.12/site-packages/pycparser/utils/fake_libc_include'
    
    include_paths = ' '.join(f'-I{inc_dir}' for inc_dir in include_dirs)
    cpp_command = f'cpp -I{fake_libc_include} {include_paths} {input_file} > {output_file}'

    try:
        subprocess.run(cpp_command, shell=True, check=True)
        print(f"Preprocessing complete. Output saved to '{output_file}'.")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while running cpp: {e}")

def remove_preprocessor_directives(file_path: str):
    with open(file_path, 'r') as file:
        content = file.read()

    pattern = re.compile(r'^\s*#.*$', re.MULTILINE)
    cleaned_content = re.sub(pattern, '', content)

    with open(file_path, 'w') as file:
        file.write(cleaned_content)

def extract_function_code(code, func_def):
    start_line = func_def.coord.line - 1
    func_code_lines = []
    lines = code.splitlines()
    for i in range(start_line, len(lines)):
        func_code_lines.append(lines[i])
        if lines[i].strip().endswith('}'):
            break
    return '\n'.join(func_code_lines)

def ast_to_string(node, indent=''):
    result = []
    node_type = type(node).__name__
    result.append(f"{indent}{node_type}(")
    indent += '  '
    
    for attr in node.attr_names:
        value = getattr(node, attr, None)
        if isinstance(value, c_ast.Node):
            result.append(f"{indent}{attr}=")
            result.append(ast_to_string(value, indent + '  '))
        else:
            result.append(f"{indent}{attr}={repr(value)},")
    
    for child_name, child in node.children():
        result.append(f"{indent}{child_name}=")
        result.append(ast_to_string(child, indent + '  '))

    result.append(f"{indent[:-2]})")
    return '\n'.join(result)

def parse_preprocessed_file(preprocessed_file: str, output_json: str, project_name: str, excluded_functions=None):
    if excluded_functions is None:
        excluded_functions = []

    with open(preprocessed_file, 'r') as file:
        code = file.read()

    parser = c_parser.CParser()
    ast = parser.parse(code)

    typedef_remover = TypedefRemover()
    typedef_remover.visit(ast)
    
    function_visitor = FunctionVisitor()
    function_visitor.visit(ast)
    
    functions_data = []

    for func_def in function_visitor.functions:
        func_name = func_def.decl.name
        if func_name in excluded_functions:
            continue  # Skip excluded functions
        func_code = extract_function_code(code, func_def)
        func_ast = ast_to_string(func_def)
        
        functions_data.append({
            'function_name': func_name,
            'function_code': func_code,
            'function_ast': func_ast
        })
    
    json_output = {
        'project_name': project_name,
        'functions': functions_data
    }

    with open(output_json, 'w') as json_file:
        json.dump(json_output, json_file, indent=4)
    print(f"Function definitions and ASTs saved to '{output_json}'.")

def process_projects_in_directory(base_dir: str, output_dir: str, excluded_functions=None, clean_up=False):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    for root, dirs, files in os.walk(base_dir):
        for sub_dir in dirs:
            subfolder_path = os.path.join(root, sub_dir)
            for project_folder in os.listdir(subfolder_path):
                project_path = os.path.join(subfolder_path, project_folder)
                if os.path.isdir(project_path):
                    print(f"Processing project: {project_path}")
                    project_name = project_folder

                    concatenated_file = os.path.join(output_dir, f"{project_name}_concatenated.c")
                    preprocessed_file = os.path.join(output_dir, f"{project_name}_preprocessed.c")
                    output_json = os.path.join(output_dir, f"{project_name}.json")

                    include_dirs = [project_path]

                    try:
                        concatenate_files(project_path, concatenated_file)
                        preprocess_c_file(concatenated_file, preprocessed_file, include_dirs)
                        remove_preprocessor_directives(preprocessed_file)
                        parse_preprocessed_file(preprocessed_file, output_json, project_name, excluded_functions)

                    except (ParseError, subprocess.CalledProcessError) as e:
                        print(f"Skipping project '{project_name}' due to error: {e}")
                    
                    finally:
                        # Clean up temporary files if specified
                        if clean_up:
                            if os.path.exists(concatenated_file):
                                os.remove(concatenated_file)
                            if os.path.exists(preprocessed_file):
                                os.remove(preprocessed_file)
                            print(f"Temporary files deleted for project '{project_name}'.")

if __name__ == "__main__":
    source_dir = "../data_clean/inf155-202403-tp1"
    output_dir = "../data_ast"
    excluded_functions = ['pile_empiler', 'pile_depiler','pile_est_vide', 'pile_contient', 'pile_haut_pile', 'pile_taille_pile', 'pile_initialiser', 'pile_copier' ]
    clean_up_temp_files = True  # Set to True to clean up concatenated and preprocessed files

    process_projects_in_directory(source_dir, output_dir, excluded_functions, clean_up=clean_up_temp_files)

