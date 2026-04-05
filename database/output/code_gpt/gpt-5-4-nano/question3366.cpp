/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, string> db;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "CLOSE") {
            break;
        } else if (cmd == "POST") {
            int id;
            string data;
            cin >> id;
            cin >> data;
            if ((int)db.size() >= 100) {
                cout << "Banco cheio!\n";
            } else {
                db[id] = data;
                cout << "Adicionado: " << id << " " << data << "\n";
            }
        } else if (cmd == "PUT") {
            int id;
            string data;
            cin >> id;
            cin >> data;
            auto it = db.find(id);
            if (it == db.end()) {
                cout << "ID não encontrado!\n";
            } else {
                it->second = data;
                cout << "Atualizado: " << id << " " << data << "\n";
            }
        } else if (cmd == "DELETE") {
            int id;
            cin >> id;
            auto it = db.find(id);
            if (it == db.end()) {
                cout << "ID não encontrado!\n";
            } else {
                cout << "Excluido: " << id << " " << it->second << "\n";
                db.erase(it);
            }
        } else if (cmd == "GET") {
            int id;
            cin >> id;
            auto it = db.find(id);
            if (it == db.end()) {
                cout << "ID não encontrado!\n";
            } else {
                cout << "Enviado: " << id << " " << it->second << "\n";
            }
        }
    }

    cout << "Dados no banco:\n";
    for (const auto &p : db) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}