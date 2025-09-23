import requests
import os
from dotenv import load_dotenv
import pandas as pd

load_dotenv()

TOKEN = os.getenv("TOKEN_THE_HUXLEY")

if not TOKEN:
    print("ERRO: TOKEN_THE_HUXLEY não foi encontrado no seu arquivo .env")
    exit()

database = pd.DataFrame(columns=['id', 'name', 'level', 'time', 'evaluation'])

for problem_id in range(2, 5000):
    url = f"https://www.thehuxley.com/api/v1/user/problems/{problem_id}/submissions"

    params = {
        'currentPage': 1,
        'max': 10,
        'offset': 0,
        'order': 'desc',
        'sort': 'submissionDate'
    }

    headers = {
        "Accept": "application/json, text/plain, */*",
        "Authorization": TOKEN,
        "Referer": f"https://www.thehuxley.com/problem/{problem_id}/",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:142.0) Gecko/20100101 Firefox/142.0",
    }

    cookies = {
        "tha": TOKEN,
    }

    print(f"Buscando submissões para o problema ID: {problem_id}...")

    try:
        response = requests.get(url, headers=headers,
                                cookies=cookies, params=params)
        response.raise_for_status()
        data = response.json()

        # print(data)

        if len(data) != 0:
            # id data[0]["problem"]['id']
            # name data[0]["problem"]['name']
            # time print(data[0]['time'])
            # print(data[0]['evaluation'])
            print(data[0])
            response_problem = requests.get(
                f"https://www.thehuxley.com/api/v1/problems/{problem_id}?locale=pt_BR")

            if response_problem.status_code == 200:
                data_problem = response_problem.json()
                # print(data_problem)

                database.loc[len(database)] = [data[0]["problem"]['id'], data[0]["problem"]
                                               ['name'], data_problem["level"], data[0]['time'], data[0]['evaluation']]

                print("✅ Requisição bem-sucedida!")
                print("-" * 50)
            else:
                print("❌ Não houve requisição level problem")
        else:
            print("❌ Não houve requisição")

    except requests.exceptions.HTTPError as err:
        print(f"❌ Erro na requisição: {err}")
        print(f"   Status Code: {err.response.status_code}")
        print(f"   Resposta do servidor: {err.response.text}")
    except requests.exceptions.RequestException as e:
        print(f"❌ Ocorreu um erro de conexão: {e}")

database.to_csv('result_send_code.csv', index=False)
