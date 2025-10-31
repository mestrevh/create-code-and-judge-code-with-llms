/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <string>
#include <list>

int main() {
    int N;
    std::cin >> N;
    std::list<std::string> toupeiras;
    std::string nome, consulta;

    std::cin.ignore();
    std::getline(std::cin, nome);
    std::istringstream iss(nome);
    while (iss >> nome) {
        toupeiras.push_back(nome);
    }
    
    std::getline(std::cin, consulta);

    int count = 0;
    for (const auto& toupeira : toupeiras) {
        if (toupeira == consulta) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    return 0;
}
