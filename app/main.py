from services.database_services import DatabaseServices
from core.llm_orchestrator import LLMOrchestrator
from services.gemini_service import GeminiService
from services.gpt_services import GPTService

def main ():
    print("=" * 30)
    print("Iniciando o sistema!")
    print("=" * 30)
    
    while True:
        
        print("**** MENU *****")
        print("1 - Criar a base de dados com poucos casos de testes;")
        print("2 - Criar a base de dados com casos de testes possível (demora dias);")
        print("3 - Dinâmica: uma llm cria o código e outra llm julga o código.")
        print("4 - Dinâmica: fazer dinâmica 3 em comparação com the huxley;")
        print("Para sair digite qualquer coisa que não está no menu")
        
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
        else:
            exit()
    

if __name__ == "__main__":
    main()