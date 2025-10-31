/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, std::string> charToAnimal = {
        {"Coragem", "Sapos"},
        {"Determinacao", "Sapos"},
        {"Conviccao", "Sapos"},
        {"Ambicao", "Cobras"},
        {"Astucia", "Cobras"},
        {"Expertise", "Cobras"},
        {"Analise", "Lesmas"},
        {"Suporte", "Lesmas"},
        {"Tecnica", "Lesmas"},
        {"Agilidade", "Macacos"},
        {"Inteligencia", "Macacos"},
        {"Destreza", "Macacos"},
        {"Experiencia", "Caes"},
        {"Perspicacia", "Caes"},
        {"Pericia", "Caes"}
    };

    std::map<std::string, std::vector<std::string>> contracts;
    int totalContracts = 0;

    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        
        std::stringstream ss(line);
        std::string name, characteristic;
        
        ss >> name;
        if (ss >> characteristic) {
            if (charToAnimal.count(characteristic)) {
                contracts[charToAnimal.at(characteristic)].push_back(name);
                totalContracts++;
            }
        }
    }

    if (totalContracts == 0) {
        std::cout << "Nao havera Jounins forte esse ano" << std::endl;
    } else {
        std::vector<std::string> order = {"Sapos", "Cobras", "Lesmas", "Macacos", "Caes"};
        
        for (const std::string& animal : order) {
            std::cout << animal << ":" << std::endl;
            if (contracts.count(animal)) {
                for (const std::string& ninja : contracts.at(animal)) {
                    std::cout << "- " << ninja << std::endl;
                }
            }
        }
    }

    return 0;
}
