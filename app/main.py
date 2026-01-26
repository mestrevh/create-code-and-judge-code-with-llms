from services import DatabaseServices

def main ():
    print("=" * 30)
    print("Iniciando o sistema!")
    print("=" * 30)
    
    while True:
        
        print("**** MENU *****")
        print("1 - Criar a base de dados com poucos casos de testes")
        print("2 - Criar a base de dados com casos de testes possível (demora dias)")
        
        op = int(input("Escolha uma opção (numero): "))
            
        database_service = DatabaseServices()
        
        if op == 1:
            database_service.create_database(cases_test=False)
        elif op == 2:
            database_service.create_database(cases_test=True)
        else:
            exit()
    

if __name__ == "__main__":
    main()