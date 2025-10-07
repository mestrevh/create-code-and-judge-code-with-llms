/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<int, std::string> database;
    const int MAX_SIZE = 100;
    std::string command;

    while (std::cin >> command) {
        if (command == "CLOSE") {
            break;
        }

        if (command == "POST") {
            int id;
            std::string data;
            std::cin >> id >> data;
            if (database.size() >= MAX_SIZE) {
                std::cout << "Banco cheio!\n";
            } else {
                database[id] = data;
                std::cout << "Adicionado: " << id << " " << data << "\n";
            }
        } else if (command == "PUT") {
            int id;
            std::string newData;
            std::cin >> id >> newData;
            auto it = database.find(id);
            if (it != database.end()) {
                it->second = newData;
                std::cout << "Atualizado: " << id << " " << newData << "\n";
            } else {
                std::cout << "ID não encontrado!\n";
            }
        } else if (command == "DELETE") {
            int id;
            std::cin >> id;
            auto it = database.find(id);
            if (it != database.end()) {
                std::string oldData = it->second;
                database.erase(it);
                std::cout << "Excluido: " << id << " " << oldData << "\n";
            } else {
                std::cout << "ID não encontrado!\n";
            }
        } else if (command == "GET") {
            int id;
            std::cin >> id;
            auto it = database.find(id);
            if (it != database.end()) {
                std::cout << "Enviado: " << id << " " << it->second << "\n";
            } else {
                std::cout << "ID não encontrado!\n";
            }
        }
    }

    std::cout << "Dados no banco:\n";
    for (const auto& pair : database) {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}
