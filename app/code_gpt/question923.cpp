/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> perguntas = {
        "Telefonou para a vitima?",
        "Esteve no local do crime?",
        "Mora perto da vitima?",
        "Devia para a vitima?",
        "Ja trabalhou com a vitima?"
    };
    
    int respostas[5];
    int count = 0;

    for (int i = 0; i < 5; i++) {
        std::cin >> std::boolalpha >> respostas[i];
        if (respostas[i]) count++;
    }

    for (const auto& pergunta : perguntas) {
        std::cout << pergunta << std::endl;
    }

    if (count == 0) {
        std::cout << "Inocente" << std::endl;
    } else if (count == 1) {
        std::cout << "Inocente" << std::endl;
    } else if (count == 2) {
        std::cout << "Suspeita" << std::endl;
    } else if (count >= 3 && count <= 4) {
        std::cout << "Cumplice" << std::endl;
    } else if (count == 5) {
        std::cout << "Assassino" << std::endl;
    }

    return 0;
}
