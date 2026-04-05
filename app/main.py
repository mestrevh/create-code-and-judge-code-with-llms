from services.database_services import DatabaseServices
from core.llm_orchestrator import LLMOrchestrator
from services.gemini_service import GeminiService
from services.gpt_services import GPTService
from pathlib import Path
from utils.file_manager import file_manager
from utils.build_website import BuildWebsite

# [54, 812, 684, 814, 817, 813, 2201, 3598, 373, 3599, 176, 3601, 4662] analise obi

def main ():
    print("=" * 30)
    print("Iniciando o sistema!")
    print("=" * 30)
    
    while True:
        
        print("**** MENU *****")
        print("1 - Criar a base de dados com poucos casos de testes;")
        print("2 - Criar a base de dados com casos de testes possível (demora dias);")
        print("3 - Dinâmica: uma llm cria o código e outra llm julga o código;")
        print("4 - Dinâmica: fazer Dinâmica 3 em comparação com the huxley;")
        print("5 - Converter output/file.csv para output/file.json (vice-versa);")
        print("6 - Testar todas as questões usando a Dinâmica 4;")
        print("7 - Escolher as questões e fazer Dinâmica 3.")
        print("8 - Construir website das questões (com base em database/questions).")
        print("Para sair digite qualquer coisa que não está no menu.")
        
        op = input("Escolha uma opção (numero): ")
        
        database_service = DatabaseServices()
        
        if op == "1":
            database_service.create_database(cases_test=False)
        
        elif op == "2":
            database_service.create_database(cases_test=True)
        
        elif op == "3":
            database_service.build_questions_id()
            questions_id = database_service.get_problems()
            
            while True:
                print("Numeração dos problemas: database/questions/question[numero]")
                print(questions_id)
                
                try:
                    id = int(input("Digite um número: "))
                    problem = database_service.get_problem(id)
                    
                    if not problem.problem_is_exist():
                        continue
                    
                    while True:
                        print("**** MENU *****")
                        print("1 - Code Gemini vs judger GPT")
                        print("2 - Code GPT vs judger Gemini")
                        print("Para sair digite qualquer coisa que não está no menu")
                        struct = input("Escolha uma opção: ")

                        if struct == "1":
                            coder = GeminiService()
                            judger = GPTService()
                            
                            orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                            if not orchestrator.create_and_judge_code(problem=problem):
                                print("Erro na execução da dinâmica!")
                            
                            print("=" * 10 + "Voltando ao menu" + "=" * 10)
                        elif struct == "2":
                            coder = GPTService()
                            judger = GeminiService()
                            
                            orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                            if not orchestrator.create_and_judge_code(problem=problem):
                                print("Erro na execução da dinâmica!")
                            
                            print("=" * 10 + "Voltando ao menu" + "=" * 10)
                        else:
                            break
                        
                    break
                except ValueError:
                    print("Não é um número! Digite novamente.")
       
        elif op == "4":
            database_service.build_questions_id()
            questions_id = database_service.get_problems()
            
            while True:
                print("Numeração dos problemas: database/questions/question[numero]")
                print(questions_id)
                
                try:
                    id = int(input("Digite um número: "))
                    problem = database_service.get_problem(id)
                    
                    if not problem.problem_is_exist():
                        continue
                    
                    while True:
                        print("**** MENU *****")
                        print("1 - Code Gemini vs GPT simulation the huxley")
                        print("2 - Code GPT vs Gemini simulation the huxley")
                        print("Para sair digite qualquer coisa que não está no menu")
                        struct = input("Escolha uma opção: ")

                        if struct == "1":
                            coder = GeminiService()
                            judger = GPTService()
                            
                            orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                            if not orchestrator.simulation_the_huxley_with_llm(problem=problem):
                                print("Erro na execução da dinâmica!")
                            
                            print("=" * 10 + "Voltando ao menu" + "=" * 10)
                        elif struct == "2":
                            coder = GPTService()
                            judger = GeminiService()
                            
                            orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                            if not orchestrator.simulation_the_huxley_with_llm(problem=problem):
                                print("Erro na execução da dinâmica!")
                            
                            print("=" * 10 + "Voltando ao menu" + "=" * 10)
                        else:
                            break
                        
                    break
                except ValueError:
                    print(f"[Erro]: Não é um número! Digite novamente.")
        
        elif op == "5":
            
             while True:
                print("**** MENU *****")
                print("1 - CSV para JSON")
                print("2 - JSON para CSV")
                print("Para sair digite qualquer coisa que não está no menu")
                struct = input("Escolha uma opção: ")
                
                if file_manager.create_dir("database/output/csv"):
                        print("Diretorio database/output/csv/ criado!!!!")
                    
                if file_manager.create_dir("database/output/json"):
                        print("Diretorio database/output/json/ criado!!!!")
                        
                if struct == "1":
                    
                    path = Path("database/output/csv")
                    names = [file.stem for file in path.glob("*.csv")]
                    name = ""
                    
                    if names:
                        while not (name in names):
                            print("Nomes dos arquivos: ")
                            for n in names:
                                print(n)
                            
                            name = input("Escolha um nome: ")
                        
                        if file_manager.csv_to_json("database/output", name):
                            print("Tudo certo!!!!")
                        else:
                            print("Tente novamente!!!!")
                    else:
                        print("Diretorio não possui arquivos!!!!!")
                        
                elif struct == "2":

                        
                    path = Path("database/output/json")
                    names = [file.stem for file in path.glob("*.json")]
                    name = ""
                    
                    if names:
                        while not (name in names):
                            print("Nomes dos arquivos: ")
                            for n in names:
                                print(n)
                            
                            name = input("Escolha um nome: ")
                        
                        if file_manager.json_to_csv("database/output", name):
                            print("Tudo certo!!!!")
                        else:
                            print("Tente novamente!!!!")
                    else:
                        print("Diretorio não possui arquivos!!!!!")
                        
                else:
                    break
        
        elif op == "6":
            path = Path("database/questions/")
            problems_id = [int(dir.name.replace("question", "")) for dir in path.iterdir() if dir.is_dir()]
            
            print("**** MENU *****")
            print("1 - Code Gemini vs GPT simulation the huxley")
            print("2 - Code GPT vs Gemini simulation the huxley")
            print("Para sair digite qualquer coisa que não está no menu")
            struct = input("Escolha uma opção: ")
            
            if struct == "1":
                coder = GeminiService()
                judger = GPTService()
                
                for id in problems_id:
                    print("id: ", id)
                    problem = database_service.get_problem(id)
                    orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                    print(f"Questão id: {id}")
                    if not orchestrator.simulation_the_huxley_with_llm(problem=problem):
                        print("Erro na execução da dinâmica!")
                        
            elif struct == "2":
                coder = GPTService()
                judger = GeminiService()
                
                for id in problems_id:
                    problem = database_service.get_problem(id)
                    orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                    print(f"Questão id: {id}")
                    if not orchestrator.simulation_the_huxley_with_llm(problem=problem):
                        print("Erro na execução da dinâmica!")
            else:
                print("=" * 10 + "Voltando ao menu" + "=" * 10)
        
        elif op == "7":
            print("**** MENU *****")
            print("1 - Code Gemini vs GPT simulation the huxley")
            print("2 - Code GPT vs Gemini simulation the huxley")
            print("Para sair digite qualquer coisa que não está no menu")
            struct = input("Escolha uma opção: ")
            
            n = 0
            problems_id = []
            
            while True:
                try:
                    n = int(input("Número de questões: "))
                    
                    questions_id = database_service.get_problems()
                    print(str(questions_id))
                    
                    while len(problems_id) != n:
                        try:
                            id = int(input())
                            
                            if id in questions_id:
                                problems_id.append(id)
                                print(f"Falta {n - len(problems_id)} questões")
                            else:
                                print("Esse id não está no banco de dados!!!")
                        except ValueError:
                            print("Digite apenas o número!")
                    
                    break
                except ValueError:
                    print("Não é um número! Digite novamente.")
                    
            if struct == "1":
                coder = GeminiService()
                judger = GPTService()
                
                for id in problems_id:
                    problem = database_service.get_problem(id)
                    orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                    if not orchestrator.create_and_judge_code(problem=problem):
                        print("Erro na execução da dinâmica!")
                                
                        print("=" * 10 + "Voltando ao menu" + "=" * 10)
                        
            elif struct == "2":
                coder = GPTService()
                judger = GeminiService()
                
                for id in problems_id:
                    problem = database_service.get_problem(id)
                    orchestrator = LLMOrchestrator(coder=coder, judger=judger)
                    if not orchestrator.create_and_judge_code(problem=problem):
                        print("Erro na execução da dinâmica!")
                                
                        print("=" * 10 + "Voltando ao menu" + "=" * 10)
            else:
                print("=" * 10 + "Voltando ao menu" + "=" * 10)
        
        elif op == "8":
            website = BuildWebsite()
            del website
            
        else:
            exit()
    

if __name__ == "__main__":
    main()