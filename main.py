import os
from google import genai
from dotenv import load_dotenv

load_dotenv()

gemini_api_key = os.getenv("GEMINI_API_KEY")

client = genai.Client(api_key=gemini_api_key)

response = client.models.generate_content(
    model="gemini-2.5-flash",
    contents="Faça um programa em C para bubble sort. Responda apenas com o código, sem comentários ou texto extra."
)

print(response.text)

codigo_c = response.text
codigo_c = codigo_c.strip("`")
codigo_c = codigo_c[1:]

with open("code/bubble_sort.c", "w", encoding="utf-8") as f:
    f.write(codigo_c)

print(codigo_c)
print("Arquivo bubble_sort.c gerado com sucesso!")

def main():
    print(gemini_api_key)

main()