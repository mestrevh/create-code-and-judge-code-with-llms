/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> db;
    string cmd;

    while (cin >> cmd && cmd != "CLOSE") {
        if (cmd == "POST") {
            int id;
            string data;
            cin >> id >> data;
            if (db.count(id)) {
                db[id] = data;
                cout << "Adicionado: " << id << " " << data << "\n";
            } else if (db.size() < 100) {
                db[id] = data;
                cout << "Adicionado: " << id << " " << data << "\n";
            } else {
                cout << "Banco cheio!\n";
            }
        } else if (cmd == "PUT") {
            int id;
            string data;
            cin >> id >> data;
            if (db.count(id)) {
                db[id] = data;
                cout << "Atualizado: " << id << " " << data << "\n";
            } else {
                cout << "ID não encontrado!\n";
            }
        } else if (cmd == "DELETE") {
            int id;
            cin >> id;
            if (db.count(id)) {
                cout << "Excluido: " << id << " " << db[id] << "\n";
                db.erase(id);
            } else {
                cout << "ID não encontrado!\n";
            }
        } else if (cmd == "GET") {
            int id;
            cin >> id;
            if (db.count(id)) {
                cout << "Enviado: " << id << " " << db[id] << "\n";
            } else {
                cout << "ID não encontrado!\n";
            }
        }
    }

    cout << "Dados no banco:\n";
    for (auto const& [id, data] : db) {
        cout << id << " " << data << "\n";
    }

    return 0;
}