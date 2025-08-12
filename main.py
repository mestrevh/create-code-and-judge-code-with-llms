import os
from google import genai
from dotenv import load_dotenv

load_dotenv()

gemini_api_key = os.getenv("GEMINI_API_KEY")

client = genai.Client(api_key=gemini_api_key)

response = client.models.generate_content(
    model="gemini-2.5-flash",
    contents="Faça um programa de teste em c para bubble sort"
)

print(response.text)

def main():
    print(gemini_api_key)

main()