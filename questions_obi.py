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
        print("-" * 50)

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


# criar o código
def create_code(op: str = "1", i: str = "2"):

    if op != "1" and op != "2":
        print("Fim do programa!")
        return False

    question_dir = f"question{i}"
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

            code = None

            if op == "1":

                prompt = (
                    "Você é um especialista em programação programação competitiva em C++.\n"
                    "Faça um programa em C++ para o problema abaixo.\n"
                    "Responda apenas com o código, sem comentários ou texto extra.\n"
                    "O problema está no formato de string e com tags html, modifique para entender melhor o problema\n"
                    "Os links que aparecerem tente acessar e retirar informações para ajudar na resolução.\n\n"
                    f"{problem_text}"
                    "\nA saída tem que ser exatamente igual ao campo de saída esperada para conseguir passar nos testes de entradas futuras!"
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
                        "\nA saída tem que ser exatamente igual ao campo de saída esperada para conseguir passar nos testes de entradas futuras!"
                    )}
                ]

                # print(f"Prompt para {question_dir}:\n{prompt}\n{'-'*50}\n")

                code = send_prompt(type="gpt", prompt=prompt)

            # print(code)
            if code != None:

                code = code[6:len(code)-3]

                # print(code)

                if op == "1":

                    code = f'/*\nCódigo criado pelo Gemini Pro 1.5\nEstudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/' + code

                    with open(f"code_gemini/{question_dir}.cpp", "w", encoding="utf-8") as f:
                        f.write(code)

                    print(
                        f"Arquivo code_gemini/{question_dir}.cpp gerado com sucesso!")

                elif op == "2":

                    code = f'/*\nCódigo criado pelo GPT 4o-mini\nEstudo para TCC (Victor Hugo Silva Ângelo - UFAL)\n*/' + code

                    with open(f"code_gpt/{question_dir}.cpp", "w", encoding="utf-8") as f:
                        f.write(code)

                    print(
                        f"Arquivo code_gpt/{question_dir}.cpp gerado com sucesso!")

    return True


def main():
    questions = [812, 684, 814, 817, 813, 2201, 3598, 373, 3599, 176, 54, 3601]
    db_send_code = pd.DataFrame(columns=['id', 'name', 'time', 'evaluation'])

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
            for q in questions:

                if choice == "1":
                    if create_code(op=choice, i=q):
                        if send_code(code_dir="code_gemini", i=q):
                            submission = get_submission_the_huxley(q)

                            if submission[0] != None:
                                db_send_code.loc[len(db_send_code)] = [
                                    q, submission[0], submission[1], submission[2]]
                            else:
                                print("Erro ao enviar")
                                exit()
                        else:
                            print("Não foi possível enviar a questão!")

                    else:
                        print("Não foi possível criar o código")

                    db_send_code.to_csv(
                        "result_the_huxley_gemini_code.csv", index=False)

                else:
                    if create_code(op=choice):
                        if send_code(code_dir="code_gpt", i=q):
                            if submission[0] != None:
                                db_send_code.loc[len(db_send_code)] = [
                                    q, submission[0], submission[1], submission[2]]
                            else:
                                print("Erro ao enviar")
                                exit()

                        else:
                            print("Não foi possível enviar a questão!")
                    else:
                        print("Não foi possível criar o código")

                    db_send_code.to_csv(
                        "result_the_huxley_gpt_code.csv", index=False)


main()
