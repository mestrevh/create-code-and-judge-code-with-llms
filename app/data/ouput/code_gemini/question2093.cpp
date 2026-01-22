/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> ariel_visitors;
    std::vector<std::string> cinderella_visitors;
    std::vector<std::string> pocahontas_visitors;
    std::vector<std::string> jasmine_visitors;

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);

        std::string name;
        std::string preference = "";

        ss >> name;
        if (ss >> preference) {
            if (preference == "mar" || preference == "mergulho") {
                ariel_visitors.push_back(name);
            } else if (preference == "bailes" || preference == "sapatos") {
                cinderella_visitors.push_back(name);
            } else if (preference == "florestas" || preference == "pacifismo") {
                pocahontas_visitors.push_back(name);
            } else if (preference == "desertos" || preference == "tapetes") {
                jasmine_visitors.push_back(name);
            }
        }
    }

    bool any_visitors = !ariel_visitors.empty() || 
                        !cinderella_visitors.empty() || 
                        !pocahontas_visitors.empty() || 
                        !jasmine_visitors.empty();

    if (!any_visitors) {
        std::cout << "Infelizmente nao teremos passeios nessa temporada.\n";
    } else {
        if (!ariel_visitors.empty()) {
            std::cout << "Ariel:\n";
            for (const std::string& name : ariel_visitors) {
                std::cout << "- " << name << "\n";
            }
        }
        if (!cinderella_visitors.empty()) {
            std::cout << "Cinderela:\n";
            for (const std::string& name : cinderella_visitors) {
                std::cout << "- " << name << "\n";
            }
        }
        if (!pocahontas_visitors.empty()) {
            std::cout << "Pocahontas:\n";
            for (const std::string& name : pocahontas_visitors) {
                std::cout << "- " << name << "\n";
            }
        }
        if (!jasmine_visitors.empty()) {
            std::cout << "Jasmine:\n";
            for (const std::string& name : jasmine_visitors) {
                std::cout << "- " << name << "\n";
            }
        }
    }

    return 0;
}
