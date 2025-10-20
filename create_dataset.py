import requests
from pathlib import Path
from dotenv import load_dotenv
import os
import time
import csv

# Lendo variaveis de ambiente
load_dotenv()

base_dir = Path("questions")


def get_submission_the_huxley(i: int = 2):

    problem_id = str(i)

    url = f"https://www.thehuxley.com/api/v1/submissions/summary?problem={i}&stats=last"
    params = {'max': 1, 'sort': 'submissionDate', 'order': 'desc'}
    headers = {
        "Accept": "application/json, text/plain, */*",
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
            return latest_submission
        else:
            print(
                f"[get_submission_the_huxley]: Nenhuma submissão encontrada para o problema {problem_id}.")
            return None
    except Exception as e:
        print(f"[get_submission_the_huxley]: Falha ao buscar submissão: {e}")
        return None


def send_code(code, i: int = 2):
    url = f"https://www.thehuxley.com/api/v1/user/problems/{i}/submissions"
    problem_id = str(i)

    headers = {
        "Accept": "application/json, text/plain, */*",
        "Authorization": "Bearer " + os.getenv("TOKEN_THE_HUXLEY"),
        "Origin": "https://www.thehuxley.com",
        "Referer": f"https://www.thehuxley.com/problem/{problem_id}/code-editor/",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:143.0) Gecko/20100101 Firefox/14.0",
    }

    cookies = {
        "tha": os.getenv("TOKEN_THE_HUXLEY"),
    }

    files = {
        "problem": (None, problem_id),
        "language": (None, "5"),
        "file": ("solution.py", code.encode("utf-8"), "application/octet-stream")
    }

    try:
        response = requests.post(url, headers=headers,
                                 cookies=cookies, files=files)
        response.raise_for_status()

        print("Submissão enviada com sucesso!")
        print("Status:", response.status_code)
        time.sleep(60)
        return True

    except requests.exceptions.HTTPError as err:
        print(f"[send_code]: Erro na requisição: {err}")
        print("[send_code]: Status:", err.response.status_code)
        print("[send_code]: Resposta do servidor:", err.response.text)
    except requests.exceptions.RequestException as e:
        print(f"[send_code]: Ocorreu um erro de conexão: {e}")

    return False


def send_oracle(input: str = "", problem_id: int = 2):
    url = f"https://www.thehuxley.com/api/v1/problems/{problem_id}/oracle"

    headers = {
        "Accept": "application/json, text/plain, */*",
        "Content-Type": "application/json;charset=utf-8",  # Essencial para enviar JSON
        "Authorization": "Bearer " + os.getenv("TOKEN_THE_HUXLEY"),
        "Origin": "https://www.thehuxley.com",
        "Referer": f"https://www.thehuxley.com/problem/{problem_id}/oracle",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:143.0) Gecko/20100101 Firefox/143.0",
    }

    payload = {
        "input": input
    }

    try:
        response = requests.post(url, headers=headers, json=payload)
        response.raise_for_status()

        print(f"Oráculo para o problema {problem_id} consultado com sucesso!")
        time.sleep(10)

        hash = response.json().get('hash')

        try:
            print(f"Passo 2: Usando o hash para obter a saída final...")
            get_url = f"https://www.thehuxley.com/api/v1/problems/{i}/oracle/{hash}"

            response_get = requests.get(get_url, headers=headers)
            response_get.raise_for_status()

            data_get = response_get.json()
            output_value = data_get.get('output')

            return output_value

        except requests.exceptions.HTTPError as err:
            print(f"[send_oracle 2]: Erro na requisição: {err}")
            return None

    except requests.exceptions.HTTPError as err:
        print(f"[send_oracle]: Erro na requisição: {err}")
        print(f"[send_oracle]: Status: {err.response.status_code}")
        print(f"[send_oracle]: Resposta: {err.response.text}")
    except Exception as e:
        print(f"[send_oracle]: Ocorreu um erro inesperado: {e}")

    return None


with open("problemas.csv", 'r', newline='', encoding='utf-8') as f:
    problem_input = list(csv.reader(f))

for i in range(2, 5000):

    response = requests.get(
        f"https://www.thehuxley.com/api/v1/problems/{i}?locale=pt_BR")

    problem = ""

    print(f"Criando o problema {i}")

    if response.status_code == 200:
        data = response.json()

        if len(data['choices']) == 0 and data['baseLanguage'] == None:

            # print("\n---\n")
            # print("ID:", data["id"])
            # print("Título:", data["name"])
            # print("Descrição:", data["description"])

            # modelando o problema para colocar no txt
            problem += f"Título: {data["name"]}\n"

            problem += "Topicos do problema: "
            for value in data['topics']:
                problem += value["name"] + "; "

            problem += "\n"
            problem += f"Tempo limite de execução: {data["timeLimit"]} segundo(s)\n"

            problem += f"Descrição: {data["description"]}\n"
            problem += f"Formato da entrada: {data["inputFormat"]}\n"
            problem += f"Formato da saída: {data["outputFormat"]}\n"

            # criando o arquivo
            file_path = base_dir / f"question{i}" / "problem.txt"

            file_path.parent.mkdir(parents=True, exist_ok=True)
            file_path.write_text(problem, encoding='utf-8')

            print(f"Questão {i}: problem.txt criado!")
        else:
            print(f"Questão {i} não é para criar código")
            continue
    else:
        print(f"[create_database]: Erro: {response.status_code} problema {i}")
        continue

    code = "case = [input()]\n"
    code += "try:\n"
    code += "    while True:\n"
    code += "        case.append(input())\n"
    code += "except EOFError:\n"
    code += "    raise Exception(''.join([str(x) + '\\n' for x in case]))\n"

    if send_code(code, i):
        print("Código enviado com sucesso!!!")
    else:
        print(f"Erro ao enviar o código problema {i}!!!")
        continue

    submission = get_submission_the_huxley(i)

    if submission == None:
        continue

    # pre-processamento
    data = []
    inputs = []
    outputs = []
    substring = "\nException:"

    #print(submission)

    for value in submission["testCaseEvaluations"]:

        if value["errorMsg"] == None:
            
            problem_input.append([i])
            
            print(f"Erro ao tentar pegar algum input do problem {i}")
            
            filename = "problemas.csv"
            with open(filename, 'w', newline='', encoding='utf-8') as f:
                writer = csv.writer(f)
                writer.writerows(problem_input)

            print(f"Arquivo '{filename}' criado com sucesso!")
            
            continue

        init = value["errorMsg"].find(substring) + len(substring)
        error_msg = value["errorMsg"][init + 1 : len(value["errorMsg"]) - 2]

        # criando o objeto
        obj = {}
        obj["input"] = error_msg
        obj["output"] = send_oracle(error_msg, i)

        # add em data
        data.append(obj)

    if submission:
        #print(f"Inputs and outputs of question {i}")

        for x in range(len(data)):
            print(f"Input and output {x}")

            #print(f"Input:\n {data[x]['input']}")
            #print(f"\n\nOutput: \n {data[x]['output']}")

            if data[x]["input"] is not None:
                file_path = base_dir / f"question{i}" / "inputs" / f"in{x}.txt"

                file_path.parent.mkdir(parents=True, exist_ok=True)
                file_path.write_text(data[x]["input"], encoding='utf-8')

            if data[x]["output"] is not None:
                file_path = base_dir / f"question{i}" / "outputs" / f"out{x}.txt"

                file_path.parent.mkdir(parents=True, exist_ok=True)
                file_path.write_text(data[x]["output"], encoding='utf-8')
    else:
        print("Não houve submission nessa questão!!!")