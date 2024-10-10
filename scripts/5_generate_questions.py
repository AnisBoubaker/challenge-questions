import os
import json
from openai import OpenAI
from dotenv import load_dotenv

# Charger la clé OpenAI depuis le fichier .env
load_dotenv()
api_key = os.getenv('OPENAI_API_KEY')

# Initialiser le client OpenAI
client = OpenAI(api_key=api_key)

input_folder = '../data_candidates'
output_folder = '../data_questions'
system_prompt_file = '5_system_prompt.txt'  # Chemin vers le fichier contenant le prompt système

# Créer le dossier de sortie s'il n'existe pas
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# Lire le prompt système depuis le fichier
with open(system_prompt_file, 'r') as f:
    system_prompt = f.read()

# Fonction pour envoyer le message à la LLM et récupérer la question générée
def get_question_for_function(function_code, similar_codes):
    prompt = f"""
{function_code}

-- Code similaire: --
-- Code 0 -- 
{similar_codes[0]['function_code']}
-- Code 1 -- 
{similar_codes[1]['function_code']}
-- Code 2 -- 
{similar_codes[2]['function_code']}
"""
    
    chat_completion = client.chat.completions.create(
        model="gpt-4",
        messages=[
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": prompt}
        ]
    )
    
    # Accéder au texte du message directement via l'attribut `content`
    return chat_completion.choices[0].message.content.strip()

# Parcourir tous les fichiers JSON dans le dossier
for filename in os.listdir(input_folder):
    if filename.endswith('.json'):
        input_file_path = os.path.join(input_folder, filename)
        
        # Lire le fichier JSON
        with open(input_file_path, 'r') as f:
            data = json.load(f)
        
        # Pour chaque fonction, générer la question
        for function in data['functions']:
            similar_codes = sorted(function['similar_code'], key=lambda x: x['distance'])[:3]
            function_code = function['function_code']
            
            # Obtenir la question via l'API OpenAI
            question = get_question_for_function(function_code, similar_codes)
            
            # Ajouter la question au JSON
            function['question'] = question
        
        # Enregistrer le nouveau fichier JSON dans le dossier de sortie
        output_file_path = os.path.join(output_folder, filename)
        with open(output_file_path, 'w') as f:
            json.dump(data, f, indent=4)

print("Traitement terminé et fichiers JSON mis à jour avec les questions.")
