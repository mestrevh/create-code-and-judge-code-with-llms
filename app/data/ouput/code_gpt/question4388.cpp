/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int n, count = 0;
    std::cin >> n;
    std::cin.ignore(); // Ignora o caractere de nova linha

    for (int i = 0; i < n; ++i) {
        std::string placa;
        std::getline(std::cin, placa);

        // Verifica o padrão antigo e o padrão do Mercosul
        if (!((placa.size() == 7 && 
               isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && 
               isdigit(placa[3]) && 
               isalpha(placa[4]) && 
               isdigit(placa[5]) && isdigit(placa[6])) || 
              (placa.size() == 7 && 
               isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && 
               isdigit(placa[3]) && isdigit(placa[4]) && 
               isdigit(placa[5]) && isdigit(placa[6])))) {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
