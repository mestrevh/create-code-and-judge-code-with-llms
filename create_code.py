import os
import google.generativeai as genai
from openai import OpenAI
from dotenv import load_dotenv

load_dotenv()

try:
    genai.configure(api_key=os.getenv("GEMINI_API_KEY"))
except TypeError:
    print("ERRO: A variável de ambiente GEMINI_API_KEY não foi encontrada.")
    print("Certifique-se de que seu arquivo .env está correto e no mesmo diretório.")
    exit()

try:
    openAI = OpenAI(api_key=os.getenv("OPENAI_API_KEY"))
except TypeError:
    print("ERRO: A variável de ambiente OPENAI_API_KEY não foi encontrada.")
    print("Certifique-se de que seu arquivo .env está correto e no mesmo diretório.")
    exit()


def send_prompt(type="gemini", prompt="Teste"):
    
    if type == "gemini":
        
        try:
            model = genai.GenerativeModel('gemini-1.5-pro-latest')
            response = model.generate_content(prompt)

            return response.text
        except Exception as e:
            print(f"API not response: {e}")
            return None
    
    elif type == "gpt":
        
        try:
            gpt_response = openAI.responses.create(
                    model="gpt-4o-mini",
                    input=prompt
                )
        except Exception as e:
            print(f"API not response: {e}")
            return None
        
        return gpt_response.output_text
    
    else:
        return None


def main():
    
    print("Menu:")
    print("1 - Criar codigo com LLM gemini-1.5-pro-latest?")
    print("2 - Criar código com LLM gpt-4o-mini?")
    op = input("Escolha uma opção acima: ")
    
    if op != "1" and op != "2":
        print("Fim do programa!")
        exit()
        
    for question_dir in os.listdir("questions"):
        problem_path = os.path.join(
            "questions", question_dir, "problem.txt")

        inputs_text = []
        inputs_dir = os.path.join("questions", question_dir, "inputs")
        if os.path.isdir(inputs_dir):
            for input_file in sorted(os.listdir(inputs_dir)):
                input_path = os.path.join(inputs_dir, input_file)
                with open(input_path, "r", encoding="utf-8") as f:
                    input_data = f.read()
                inputs_text.append(input_data)

        outputs_text = []
        outputs_dir = os.path.join(
            "questions", question_dir, "outputs")
        if os.path.isdir(outputs_dir):
            for output_file in sorted(os.listdir(outputs_dir)):
                output_path = os.path.join(outputs_dir, output_file)
                with open(output_path, "r", encoding="utf-8") as f:
                    output_data = f.read()
                outputs_text.append(output_data)

        if os.path.isfile(problem_path):
            with open(problem_path, "r", encoding="utf-8") as f:
                problem_text = f.read()

            if len(inputs_text) == len(outputs_text):
                for i in range(len(inputs_text)):
                    problem_text += f"\nEntrada {i}:\n\n{inputs_text[i]} \n"
                    problem_text += f"\nSaída da entrada {i}:\n\n{outputs_text[i]}\n"
            else:
                for i in range(len(inputs_text)):
                    problem_text += f"\n Possivel entrada {i}:\n\n{inputs_text[i]}\n"

                for i in range(len(outputs_text)):
                    problem_text += f"\nPossível saída {i}:\n\n{outputs_text[i]}\n"
            
            code = None
            
            if op == "1":
                
                prompt = (
                    "Você é um especialista em programação programação competitiva em C++.\n"
                    "Faça um programa em C++ para o problema abaixo.\n"
                    "Responda apenas com o código, sem comentários ou texto extra.\n"
                    "O problema está no formato de string e com tags html, modifique para entender melhor o problema\n"
                    "Os links que aparecerem tente acessar e retirar informações para ajudar na resolução.\n\n"
                    f"{problem_text}"
                )

                #print(f"Prompt para {question_dir}:\n{prompt}\n{'-'*50}\n")

                code = send_prompt(type="gemini", prompt=prompt)
            
            elif op == "2":
                
                prompt = [
                    {"role": "system", "content": "Você é um especialista em programação programação competitiva em C++."},
                    {"role": "user", "content": (
                        "Faça um programa em C++ para o problema abaixo.\n"
                        "Responda apenas com o código, sem comentários ou texto extra.\n"
                        "O problema está no formato de string e com tags html, modifique para entender melhor o problema\n"
                        "Os links que aparecerem tente acessar e retirar informações para ajudar na resolução.\n\n"
                        f"{problem_text}"
                        "Siga "
                        )}
                    ]
                 
                #print(f"Prompt para {question_dir}:\n{prompt}\n{'-'*50}\n")

                code = send_prompt(type="gpt", prompt=prompt)
            
            #print(code)
            if code != None:
                
                code = code[6:len(code)-3]
                
                #print(code)
                
                if op == "1":
                    
                    code = f'/*\nCódigo criado pelo Gemini Pro 1.5\nEstudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/' + code
                    
                    with open(f"code_gemini/{question_dir}.cpp", "w", encoding="utf-8") as f:
                        f.write(code)

                    print(f"Arquivo code_gemini/{question_dir}.cpp gerado com sucesso!")
                
                elif op == "2":
                    
                    code = f'/*\nCódigo criado pelo GPT 4o-mini\nEstudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/' + code
                    
                    with open(f"code_gpt/{question_dir}.cpp", "w", encoding="utf-8") as f:
                        f.write(code)

                    print(f"Arquivo code_gpt/{question_dir}.cpp gerado com sucesso!")
    
    print("Fim do algoritmo!")

main()
