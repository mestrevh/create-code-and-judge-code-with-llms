from services import DatabaseServices

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
        print("Para sair digite qualquer coisa")
        
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
                    problem.print_problem()
                    
                    break
                except ValueError:
                    print("Não é um número! Digite novamente.")
                
        else:
            exit()
    

if __name__ == "__main__":
    main()