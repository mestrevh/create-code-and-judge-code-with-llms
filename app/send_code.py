import requests
import os
from dotenv import load_dotenv
import time

load_dotenv()

print("Menu:")
print("1 - Enviar os codigos do LLM gemini pro 2.5?")
print("2 - Enviar os codigos do LLM gpt-4o-mini?")
op = input("Escolha uma opção acima: ")

code_dir = ""

if op == "1":
    code_dir = "code_gemini"
elif op == "2":
    code_dir = "code_gpt"
else:
    print("Fim do programa!")
    exit()

for i in range(2, 5000):

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
        with open(f"C:/Users/Victo/Desktop/Ufal/create-code-and-judge-code-with-llms/{code_dir}/question{i}.cpp", 'r', encoding='utf-8') as f:
            codigo = f.read()
    except FileNotFoundError:
        print(f"ERRO: O arquivo não foi encontrado. O programa continuará.")
        continue

    print(codigo)

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

        print("Resposta:", response.json())
        print("-" * 50)

    except requests.exceptions.HTTPError as err:
        print(f"Erro na requisição: {err}")
        print("Status:", err.response.status_code)
        print("Resposta do servidor:", err.response.text)
    except requests.exceptions.RequestException as e:
        print(f"Ocorreu um erro de conexão: {e}")

print("Finalizado o algoritmo")