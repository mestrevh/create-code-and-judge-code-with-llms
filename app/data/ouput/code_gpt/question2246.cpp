/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>

int main() {
    double cachê;
    std::cin >> cachê;
    std::cin.ignore();
    
    std::string linha;
    double total = 0;
    std::map<std::string, double> preços = {{"CC", 5.0}, {"EC", 10.0}, {"outros", 15.0}};

    while (std::getline(std::cin, linha)) {
        std::istringstream iss(linha);
        std::string curso, nome;
        iss >> curso >> nome;

        if (preços.find(curso) != preços.end()) {
            total += preços[curso];
        } else {
            total += preços["outros"];
        }
    }

    if (total >= cachê) {
        std::cout << "Cebruthius!" << std::endl;
    } else {
        std::cout << "Escamou!" << std::endl;
    }

    return 0;
}
