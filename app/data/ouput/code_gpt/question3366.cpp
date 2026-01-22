/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    unordered_map<int, string> db;
    string command;
    while (true) {
        cin >> command;
        if (command == "CLOSE") {
            cout << "Dados no banco:" << endl;
            vector<pair<int, string>> sorted(db.begin(), db.end());
            sort(sorted.begin(), sorted.end());
            for (const auto& entry : sorted) {
                cout << entry.first << " " << entry.second << endl;
            }
            break;
        }
        int id;
        string data;
        if (command == "POST") {
            cin >> id >> data;
            if (db.size() >= 100) {
                cout << "Banco cheio!" << endl;
            } else {
                db[id] = data;
                cout << "Adicionado: " << id << " " << data << endl;
            }
        } else if (command == "PUT") {
            cin >> id;
            cin.ignore();
            getline(cin, data);
            if (db.find(id) != db.end()) {
                db[id] = data;
                cout << "Atualizado: " << id << " " << data << endl;
            } else {
                cout << "ID não encontrado!" << endl;
            }
        } else if (command == "DELETE") {
            cin >> id;
            if (db.find(id) != db.end()) {
                cout << "Excluido: " << id << " " << db[id] << endl;
                db.erase(id);
            } else {
                cout << "ID não encontrado!" << endl;
            }
        } else if (command == "GET") {
            cin >> id;
            if (db.find(id) != db.end()) {
                cout << "Enviado: " << id << " " << db[id] << endl;
            } else {
                cout << "ID não encontrado!" << endl;
            }
        }
    }
    return 0;
}
