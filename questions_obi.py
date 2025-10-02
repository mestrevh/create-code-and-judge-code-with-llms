import os
from openai import OpenAI
import google.generativeai as genai
from dotenv import load_dotenv
import requests
import time
import pandas as pd

# Lendo variaveis de ambiente
load_dotenv()

# Configurando API's
try:
    genai.configure(api_key=os.getenv("GEMINI_API_KEY"))
except TypeError:
    print("[conf-gemini]: A variável de ambiente GEMINI_API_KEY não foi encontrada.")
    print("[conf-gemini]: Certifique-se de que seu arquivo .env está correto e no mesmo diretório.")
    exit()

try:
    openAI = OpenAI(api_key=os.getenv("OPENAI_API_KEY"))
except TypeError:
    print("[conf-gpt]: A variável de ambiente OPENAI_API_KEY não foi encontrada.")
    print("[conf-gpt]: Certifique-se de que seu arquivo .env está correto e no mesmo diretório.")
    exit()


# Enviar o código no the huxley
def send_code(code_dir: str = "code_gemini", i: int = 2):
    url = f"https://www.thehuxley.com/api/v1/user/problems/{i}/submissions"

    headers = {
        "Accept": "application/json, text/plain, */*",
        "Authorization": "Bearer " + os.getenv("TOKEN_THE_HUXLEY"),
        "Origin": "https://www.thehuxley.com",
        "Referer": f"https://www.thehuxley.com/problem/{i}/code-editor/",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:142.0) Gecko/20100101 Firefox/142.0",
    }

    cookies = {
        "tha": os.getenv("TOKEN_THE_HUXLEY"),
    }

    try:
        with open(f"{code_dir}/question{i}.cpp", 'r', encoding='utf-8') as f:
            codigo = f.read()
    except FileNotFoundError:
        print(f"ERRO: O arquivo não foi encontrado. O programa continuará.")

    # print(codigo)

    files = {
        "problem": (None, i),
        "language": (None, "4"),
        "file": ("A.cpp", codigo.encode("utf-8"), "application/octet-stream")
    }

    try:
        response = requests.post(url, headers=headers,
                                 cookies=cookies, files=files)
        response.raise_for_status()

        print("Submissão enviada com sucesso!")
        print("Status:", response.status_code)

        time.sleep(30)

        #print("Resposta:", response.json())
        #print("-" * 50)

        return True

    except requests.exceptions.HTTPError as err:
        print(f"[send_code]: Erro na requisição: {err}")
        print("[send_code]: Status:", err.response.status_code)
        print("[send_code]: Resposta do servidor:", err.response.text)
    except requests.exceptions.RequestException as e:
        print(f"[send_code]: Ocorreu um erro de conexão: {e}")

    return False

# Obter a resposta do the huxley


def get_submission_the_huxley(i: int = 2):

    problem_id = str(i)
    url = f"https://www.thehuxley.com/api/v1/user/problems/{problem_id}/submissions"
    # Simplificado para pegar só o mais recente
    params = {'max': 1, 'sort': 'submissionDate', 'order': 'desc'}
    headers = {
        "Accept": "application/json, text/plain, */*",
        # <-- CORREÇÃO 2 (aplicada aqui também)
        "Authorization": "Bearer " + os.getenv("TOKEN_THE_HUXLEY"),
        "Referer": f"https://www.thehuxley.com/problem/{problem_id}/",
    }
    cookies = {"tha": os.getenv("TOKEN_THE_HUXLEY")}

    try:
        print(f"Buscando submissões para o problema ID: {problem_id}...")
        response = requests.get(url, headers=headers,
                                cookies=cookies, params=params)
        response.raise_for_status()
        data = response.json()

        if data and len(data) > 0:
            latest_submission = data[0]
            return (latest_submission.get('problem', {}).get('name'), latest_submission.get('time'), latest_submission.get('evaluation'))
        else:
            print(
                f"[get_submission_the_huxley]: Nenhuma submissão encontrada para o problema {problem_id}.")
            return (None, None)
    except Exception as e:
        print(f"[get_submission_the_huxley]: Falha ao buscar submissão: {e}")
        return (None, None)


# Enviar o prompt para API
def send_prompt(type="gemini", prompt="Teste"):

    if type == "gemini":

        try:
            model = genai.GenerativeModel("models/gemini-2.5-pro")
            response = model.generate_content(prompt)

            return response.text

        except Exception as e:
            print(f"[send_prompt]: API not response: {e}")
            return None

    elif type == "gpt":

        try:
            gpt_response = openAI.responses.create(
                model="gpt-4.1",
                input=prompt
            )
        except Exception as e:
            print(f"[send_prompt]: API not response: {e}")
            return None

        return gpt_response.output_text

    else:
        return None


def get_question_format_prompt(id : str = "2"):
    question_dir = f"question{id}"
    print(question_dir)
    problem_path = os.path.join("questions", question_dir, "problem.txt")

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
    
    return problem_text

# criar o código
def create_code(op: str = "1", i: str = "2"):

    if op != "1" and op != "2":
        print("Fim do programa!")
        return False

    problem_text = get_question_format_prompt(id=i)
    question_dir = f"question{i}"
    code = None
    
    if problem_text == None:
        return False
    
    if op == "1":

            prompt = (
                "Você é um especialista em programação programação competitiva em C++.\n"
                "Faça um programa em C++ para o problema abaixo.\n"
                "Responda apenas com o código, sem comentários ou texto extra.\n"
                "O problema está no formato de string e com tags html, modifique para entender melhor o problema\n"
                "Os links que aparecerem tente acessar e retirar informações para ajudar na resolução.\n\n"
                f"{problem_text}"
                "A saída tem que ser exatamente igual ao campo de saída esperada para conseguir passar nos testes de entradas futuras!"
                "O tempo limite de execução deve ser considerado o que a questão informa, para melhorar o resultado!"
                )

            # print(f"Prompt para {question_dir}:\n{prompt}\n{'-'*50}\n")
                
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
                    "A saída tem que ser exatamente igual ao campo de saída esperada para conseguir passar nos testes de entradas futuras!"
                    "O tempo limite de execução deve ser considerado o que a questão informa, para melhorar o resultado!"
                    )},
                ]

                # print(f"Prompt para {question_dir}:\n{prompt}\n{'-'*50}\n")

    code = send_prompt(type="gpt", prompt=prompt)

    # print(code)
    if code != None:
        code = code[6:len(code)-3]
    else:
        return False
    
    # print(code)

    if op == "1":

        code = f'/*\nCódigo criado pelo modelo gemini-2.5-pro\nEstudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/' + code

        with open(f"code_gemini/{question_dir}.cpp", "w", encoding="utf-8") as f:
            f.write(code)

            print(f"Arquivo code_gemini/{question_dir}.cpp gerado com sucesso!")

    elif op == "2":

        code = f'/*\nCódigo criado pelo modelo gpt-4.1\nEstudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/' + code

        with open(f"code_gpt/{question_dir}.cpp", "w", encoding="utf-8") as f:
            f.write(code)

        print(f"Arquivo code_gpt/{question_dir}.cpp gerado com sucesso!")

    return True

def judge_code(op: str = "1", i: str = "2") -> bool:
    
    problem_text = get_question_format_prompt(id=i)
    print(f"Judge question{i}: ")
    
    code = None
    result = None
    
    if problem_text == None:
        return None
    
    if op == "1":
        
        try:
            with open(f"code_gemini/question{i}.cpp", 'r', encoding='utf-8') as f:
                code = f.read()
        except FileNotFoundError:
            print(f"ERRO: O arquivo não foi encontrado. O programa continuará.")
            return None
            
        prompt = (
                "Você é um especialista em programação competitiva em C++.\n"
                "Analise esse código, não precisa informa nada sobre analise no output e aguarde os próximos passos.\n"
                f"\n{code}\n\n"
                "Passo 1: Você é um especialista em programação competitiva, compile o código acima e execute. A partir da questão abaixo coloque as entradas e verifique se está condizendo com a saída esperada. Não gere nenhum output nesse passo.\n"
                f"\n{problem_text}\n\n"
                "Crie entradas para questão para testar ao seu critério, não precisa informa quais são as entradas. Haverá essas opções de resposta:\n\n",
                "[CORRECT]: se acertou os testes da questão\n"
                "[WRONG_ANSWER]: errou algum teste\n"
                "[TIME_LIMIT_EXCEEDED]: passou do tempo limite de execução para algum teste feito\n"
                "[RUNTIME_ERROR]: houve algum erro durante a execução do código\n"
                "[COMPILATION_ERROR]: não conseguiu compilar o código\n"
                "[EMPTY_ANSWER]: apresentou alguma saída vazia nos testes\n"
                "Responda esse prompt apenas com os valores que estão entre [] (sem as []) nas opções de resposta, além do tempo de execução. Saída deve ser asssim: TEMPO,RESPOSTA\n"
                )

        #print(f"Prompt para :\n{prompt}\n{'-'*50}\n")
                
        result = send_prompt(type="gemini", prompt=prompt).split(",")
        
        prompt = (
                "Você é um especialista em programação competitiva em C++.\n"
                f"\n{problem_text}\n\n"
                "A partir da questão acima quero que você defina o nível da questão em Fácil, Médio ou Difícil. A resposta deve ser sempre uma das 3 palavras, sem comentários a mais ou explicações."
                )
        
        nivel = send_prompt(type="gpt", prompt=prompt)
        result.append(nivel)
        
        print(result)

    elif op == "2":
        
        try:
            with open(f"code_gpt/question{i}.cpp", 'r', encoding='utf-8') as f:
                code = f.read()
        except FileNotFoundError:
            print(f"ERRO: O arquivo não foi encontrado. O programa continuará.")
            
        prompt = [
        {
            "role": "system",
            "content": "Você é um especialista em programação competitiva em C++."
        },
        {
            "role": "user",
            "content": (
                "Analise esse código, não precisa informar nada sobre análise no output e aguarde os próximos passos.\n"
                f"{code}\n\n"
                "Passo 1: Você é um especialista em programação competitiva, compile o código acima e execute. "
                "A partir da questão abaixo coloque as entradas e verifique se está condizendo com a saída esperada. "
                "Não gere nenhum output nesse passo.\n\n"
                f"{problem_text}\n\n"
                "Crie entradas para questão para testar ao seu critério, não precisa informar quais são as entradas.\n\n"
                "Haverá essas opções de resposta:\n"
                "[CORRECT]: se acertou os testes da questão\n"
                "[WRONG_ANSWER]: errou algum teste\n"
                "[TIME_LIMIT_EXCEEDED]: passou do tempo limite de execução para algum teste feito\n"
                "[RUNTIME_ERROR]: houve algum erro durante a execução do código\n"
                "[COMPILATION_ERROR]: não conseguiu compilar o código\n"
                "[EMPTY_ANSWER]: apresentou alguma saída vazia nos testes\n\n"
                "Responda esse prompt apenas com os valores que estão entre [] (retire as []) nas opções de resposta, "
                "além do tempo de execução. Saída deve ser assim: TEMPO,RESPOSTA"
            )}
        ]

        # print(f"Prompt para {question_dir}:\n{prompt}\n{'-'*50}\n")

        result = send_prompt(type="gpt", prompt=prompt).split(",")
        
        prompt = [
        {
            "role": "system",
            "content": "Você é um especialista em programação competitiva em C++."
        },
        {
            "role": "user",
            "content": (
                f"{problem_text}\n\n"
                "A partir da questão acima quero que você defina o nível da questão em Fácil, Médio ou Difícil. A resposta deve ser sempre uma das 3 palavras, sem comentários a mais ou explicações."
            )}
        ]
        
        nivel = send_prompt(type="gpt", prompt=prompt)
        result.append(nivel)
        
        print(result)
    
    return result

def main():
    #questions = [54]
    questions = [54, 812, 684, 814, 817, 813, 2201, 3598, 373, 3599, 176, 3601, 4662]
    db_send_code = pd.DataFrame(columns=['id', 'name', 'time', 'evaluation'])
    db_send_judge = pd.DataFrame(columns=['id', 'name', 'time', 'evaluation', 'nivel'])

    while True:
        print("\n\nMenu:")
        print("1 - gemini gerar o código vs chatgpt avalia o código")
        print("2 - chagpt gerar o código vs gemini avalia o código")
        choice = input(
            "Escolha uma das opções acima (sair - qualquer outra tecla): ")

        if choice != "1" and choice != "2":
            print("FIM DO PROGRAMA")
            exit()

        else:
        
            #for q in questions:
            #    if create_code(op=choice, i=q):
            #        print(f"Código em c++ da questão {q} foi criado!!!")
            #    else:
            #        print(f"Não foi possível criar o código em c++ da questão {q}...")
                    
                    
            for q in questions:
                
                judge = [q]
                
                if choice == "1":
                    if send_code(code_dir="code_gemini", i=q):
                        submission = get_submission_the_huxley(q)

                        if submission[0] != None:
                            db_send_code.loc[len(db_send_code)] = [q, submission[0], submission[1], submission[2]]
                            judge.append(submission[0])
                        else:
                            print("Erro ao enviar")
                    else:
                        print("Não foi possível enviar a questão!")

                    judge.extend(judge_code(op = "2", i=q))
                    
                    db_send_judge.loc[len(db_send_judge)] = judge
                    db_send_judge.to_csv("result_judge_gpt.csv", index=False)
                    db_send_code.to_csv(
                        "result_the_huxley_gemini_code.csv", index=False)

                else:
                    if send_code(code_dir="code_gpt", i=q):
                        submission = get_submission_the_huxley(q)
                        
                        if submission[0] != None:
                            db_send_code.loc[len(db_send_code)] = [
                                q, submission[0], submission[1], submission[2]]
                            judge.append(submission[0])
                        else:
                            print("Erro ao enviar")
                            exit()

                    else:
                        print("Não foi possível enviar a questão!")
                    
                    
                    judge.extend(judge_code(op = "1", i=q))
                    
                    db_send_judge.loc[len(db_send_judge)] = judge
                    
                    db_send_judge.to_csv("result_judge_gemini.csv", index=False)
                    db_send_code.to_csv("result_the_huxley_gpt_code.csv", index=False)


main()
