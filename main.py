import os
from openai import OpenAI
from google import genai
from dotenv import load_dotenv

load_dotenv()

gemini_api_key = os.getenv("GEMINI_API_KEY")
gemini_client = genai.Client(api_key=gemini_api_key)

openai_api_key = os.getenv("OPENAI_API_KEY")
openai_client = OpenAI(api_key=openai_api_key)


def main():

    gemini_response = gemini_client.models.generate_content(
        model="gemini-2.5-flash",
        contents="Faça um programa em C para bubble sort. Responda apenas com o código, sem comentários ou texto extra."
    )

    print(gemini_response.text)

    codigo_c = gemini_response.text
    codigo_c = codigo_c.strip("`")
    codigo_c = codigo_c[1:]

    with open("code/bubble_sort.c", "w", encoding="utf-8") as f:
            f.write(codigo_c)

    print(codigo_c)
    print("Arquivo bubble_sort.c gerado com sucesso!")

    response = openai_client.responses.create(
        model="gpt-4o-mini",
        input="Avalie esse código:\n" + codigo_c
    )

    print(response.output_text)

    print(gemini_api_key)
    print(openai_api_key)

main()