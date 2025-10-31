/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>

void solve() {
    std::unordered_set<std::string> enemies;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    std::string enemy_name;
    while (ss >> enemy_name) {
        enemies.insert(enemy_name);
    }

    std::set<std::string> tardis_occupants;

    std::string command;
    while (std::cin >> command) {
        if (command == "ENTRAR") {
            std::string name;
            std::cin.get();
            std::getline(std::cin, name);

            if (enemies.count(name)) {
                std::cout << "Doctor o vilao " << name << " tentou entrar na Tardis.\n";
            } else {
                tardis_occupants.insert(name);
                std::cout << name << " entrou na Tardis.\n";
            }
        } else if (command == "SAIR") {
            std::string name;
            std::cin.get();
            std::getline(std::cin, name);
            
            if (tardis_occupants.count(name)) {
                tardis_occupants.erase(name);
                std::cout << name << " saiu da Tardis.\n";
            } else {
                std::cout << name << " nao esta na Tardis.\n";
            }
        } else if (command == "VERIFICAR") {
            std::string name;
            std::cin.get();
            std::getline(std::cin, name);

            if (tardis_occupants.count(name)) {
                std::cout << name << " esta na Tardis.\n";
            } else {
                std::cout << name << " nao esta na Tardis.\n";
            }
        } else if (command == "LISTAR") {
            if (tardis_occupants.empty()) {
                std::cout << "Nao ha ninguem na Tardis no momento.\n";
            } else {
                for (const auto& person : tardis_occupants) {
                    std::cout << person << "\n";
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}
