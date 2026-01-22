/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::list<std::string> workers_order;
    std::unordered_map<std::string, std::list<std::string>::iterator> workers_map;

    std::string command;
    while (std::cin >> command) {
        if (command == "INSERIR") {
            std::string name;
            std::cin >> name;
            if (workers_map.find(name) == workers_map.end()) {
                workers_order.push_back(name);
                workers_map[name] = std::prev(workers_order.end());
            }
        } else if (command == "REMOVER") {
            std::string name;
            std::cin >> name;
            auto it_map = workers_map.find(name);
            if (it_map != workers_map.end()) {
                workers_order.erase(it_map->second);
                workers_map.erase(it_map);
            }
        } else if (command == "IMPRIMIR") {
            std::cout << "Atualmente trabalhando:\n";
            for (const std::string& name : workers_order) {
                std::cout << name << '\n';
            }
            std::cout << '\n';
        }
    }

    return 0;
}
