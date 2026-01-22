/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    
    std::vector<std::string> nomes(N);
    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, nomes[i]);
    }

    for (const auto& nome : nomes) {
        std::string primeiroNome = nome.substr(0, nome.find(' '));
        std::string sobrenome = nome.substr(nome.find(' ') + 1);
        std::cout << "Cara familia " << sobrenome << ", sentimos muito pela tragica morte de " << primeiroNome << ".\n";
        
        if (sobrenome == "Lannister") {
            std::cout << "Os campos agora o ouvirao rugir.\n";
        } else if (sobrenome == "Stark") {
            std::cout << "O inverno chega para todos.\n";
        } else if (sobrenome == "Targaryen") {
            std::cout << "Voces sao superestimados mesmo.\n";
        }
    }

    return 0;
}
