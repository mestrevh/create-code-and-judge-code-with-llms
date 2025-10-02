import requests
from pathlib import Path

base_dir = Path("questions")
    
for i in range (2, 5000):
    
    response = requests.get(f"https://www.thehuxley.com/api/v1/problems/{i}?locale=pt_BR")

    problem = ""
    
    if response.status_code == 200:
        data = response.json()
        
        if len(data['choices']) == 0 and data['baseLanguage'] == None:
            
            #print("\n---\n")
            #print("ID:", data["id"])
            #print("Título:", data["name"])
            #print("Descrição:", data["description"])
            
            #modelando o problema para colocar no txt
            problem += f"Título: {data["name"]}\n"
            
            problem += "Topicos do problema: "
            for value in data['topics']:
                problem += value["name"] + "; "
            
            problem += "\n"
            problem += f"Tempo limite de execução: {data["timeLimit"]} segundo(s)\n"
            
            problem += f"Descrição: {data["description"]}\n"
            problem += f"Formato da entrada: {data["inputFormat"]}\n"
            problem += f"Formato da saída: {data["outputFormat"]}\n"
            
            #criando o arquivo
            file_path = base_dir / f"question{i}" / "problem.txt"

            file_path.parent.mkdir(parents=True, exist_ok=True)
            file_path.write_text(problem, encoding='utf-8')
            
            print(f"Questão {i}: problem.txt criado!")
        else:
            print(f"Questão {i} não é para criar código")
            continue
    else:
        print("Erro:", response.status_code)
        continue
        
    response = requests.get(f"https://www.thehuxley.com/api/v1/problems/{i}/examples")
    
    if response.status_code == 200:
        print(f"Inputs and outputs of question {i}")
        data = response.json()
        
        for x in range(len(data)):
            print(f"Input and output {x}")
            #criando o arquivos de inputs
            
            if data[x]["input"] != None:
                file_path = base_dir / f"question{i}" / f"inputs" / f"in{x}.txt"

                file_path.parent.mkdir(parents=True, exist_ok=True)
                file_path.write_text(data[x]["input"], encoding='utf-8')
            
            if data[x]["output"] != None:
                #criando o arquivo outputs
                file_path = base_dir / f"question{i}" / f"outputs" / f"out{x}.txt"

                file_path.parent.mkdir(parents=True, exist_ok=True)
                file_path.write_text(data[x]["output"], encoding='utf-8')