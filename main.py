import os
from openai import OpenAI
from google import genai
from dotenv import load_dotenv

load_dotenv()

gemini_client = genai.Client(api_key=os.getenv("GEMINI_API_KEY"))
openai_client = OpenAI(api_key=os.getenv("OPENAI_API_KEY"))


def send_prompt (type = "gemini", prompt = "Teste"):
  
  if type == "gemini":
    gemini_response = gemini_client.models.generate_content(
      model="gemini-2.5-flash",
      contents=prompt
    )
   
    return gemini_response.text

  elif type == "gpt":
    gpt_response = openai_client.responses.create(
              model="gpt-4o-mini",
              input=prompt
          )
   
    return gpt_response.output_text
  
  else:
    return "Não existe esse tipo de llm na aplicação"


def main():

  #print(gemini_api_key)
  #print(openai_api_key)
  
  while True:
    
          print("\n\nMenu:")
          print("1 - gemini gerar o código vs chatgpt avalia o código")
          print("2 - chagpt gerar o código vs gemini avalia o código")
          op = input("Escolha uma das opções acima (sair - qualquer outra tecla): ")
          
          if op == '1':
            
            for question_dir in os.listdir("questions"):
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
              outputs_dir = os.path.join("questions", question_dir, "outputs")
              if os.path.isdir(outputs_dir):
                  for output_file in sorted(os.listdir(outputs_dir)):
                      output_path = os.path.join(outputs_dir, output_file)
                      with open(output_path, "r", encoding="utf-8") as f:
                          output_data = f.read()
                      outputs_text.append(output_data)
              
              if os.path.isfile(problem_path):
                  with open(problem_path, "r", encoding="utf-8") as f:
                      problem_text = f.read()

                  prompt_gemini = (
                      "Você é um especialista em programação C."
                      "Faça um programa em C para o problema abaixo."
                      "Responda apenas com o código, sem comentários ou texto extra.\n\n"
                      f"{problem_text}"
                  )

                  print(f"Prompt para {question_dir}:\n{prompt_gemini}\n{'-'*50}\n")
                  
                  code = send_prompt(type="gemini", prompt=prompt_gemini)
                  print(code)
                  code = code.strip("`")
                  code = code[1:]
                  
                  with open(f"code_gemini/{question_dir}.c", "w", encoding="utf-8") as f:
                      f.write(code)
            
                  print(f"Arquivo code_gemini/{question_dir}.c gerado com sucesso!")
                  
                  judge = ""
                  
                  for i in range(len(inputs_text)):
                    judge += "Entrada 1:\n"
                    judge += inputs_text[i]
                    judge += "\nSaída da entrada 1:\n"
                    judge += outputs_text[i]
                  
                  prompt_gpt = [
                      {"role": "system", "content": "Você é um avaliador de código experiente em C."},
                      {"role": "user", "content": f"Avalie esse código em C:\n\n{code}"},
                      {"role": "user", "content": f"Execute esse código em C com entradas e compare com a saída esperada. Caso der diferente saída esperada, mostre o motivo!"},
                      {"role": "user", "content": f"{judge}"}
                  ]
                  
                  answer = send_prompt(type="gpt", prompt=prompt_gpt)
                  
                  with open(f"judge_gpt/{question_dir}.md", "w", encoding="utf-8") as f:
                      f.write(answer)
                      
                  with open(f"judge_gpt/{question_dir}.txt", "w", encoding="utf-8") as f:
                      f.write(answer)
                
          elif op == '2':
            
            for question_dir in os.listdir("questions"):
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
              outputs_dir = os.path.join("questions", question_dir, "outputs")
              if os.path.isdir(outputs_dir):
                  for output_file in sorted(os.listdir(outputs_dir)):
                      output_path = os.path.join(outputs_dir, output_file)
                      with open(output_path, "r", encoding="utf-8") as f:
                          output_data = f.read()
                      outputs_text.append(output_data)
              
              if os.path.isfile(problem_path):
                  with open(problem_path, "r", encoding="utf-8") as f:
                      problem_text = f.read()

                  prompt = [
                      {"role": "system", "content": "Você é um especialista em programação C."},
                      {"role": "user", "content": (
                          "Faça um programa em C para o problema abaixo. "
                          "Responda apenas com o código, sem comentários ou texto extra.\n\n"
                          f"{problem_text}"
                      )}
                  ]

                  print(f"Prompt para {question_dir}:\n{prompt}\n{'-'*50}\n")
                  
                  code = send_prompt(type="gpt", prompt=prompt)
                  print(code)
                  code = code.strip("`")
                  code = code[1:]
                  
                  with open(f"code_gpt/{question_dir}.c", "w", encoding="utf-8") as f:
                      f.write(code)
            
                  print(f"Arquivo code_gpt/{question_dir}.c gerado com sucesso!")
                  
                  judge = ""
                  for i in range(len(inputs_text)):
                      judge += f"Entrada {i+1}:\n"
                      judge += inputs_text[i]
                      judge += f"\nSaída esperada da entrada {i+1}:\n"
                      judge += outputs_text[i]
                      judge += "\n\n"

                  prompt_gemini = (
                      "Você é um avaliador de código experiente em C.\n"
                      f"Avalie o seguinte código:\n\n{code}\n\n"
                      "Execute esse código em C com as entradas abaixo e compare com a saída esperada.\n"
                      "Caso haja diferenças, explique o motivo.\n\n"
                      f"{judge}"
                  )
                  
                  answer = send_prompt(type="gemini", prompt=prompt_gemini)
                  
                  with open(f"judge_gemini/{question_dir}.md", "w", encoding="utf-8") as f:
                      f.write(answer)
                  
                  with open(f"judge_gemini/{question_dir}.txt", "w", encoding="utf-8") as f:
                      f.write(answer)
                      

          else:
            return

main()