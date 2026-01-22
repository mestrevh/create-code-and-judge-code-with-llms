/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    set<string> enemies;
    set<string> tardis;
    string line;
    
    getline(cin, line);
    stringstream ss(line);
    string enemy;
    while (ss >> enemy) {
        enemies.insert(enemy);
    }

    while (getline(cin, line)) {
        string command, name;
        stringstream cmd_ss(line);
        cmd_ss >> command >> ws;
        getline(cmd_ss, name);

        if (command == "ENTRAR") {
            if (enemies.find(name) != enemies.end()) {
                cout << "Doctor o vilao " << name << " tentou entrar na Tardis." << endl;
            } else {
                tardis.insert(name);
                cout << name << " entrou na Tardis." << endl;
            }
        } else if (command == "SAIR") {
            if (tardis.erase(name)) {
                cout << name << " saiu da Tardis." << endl;
            } else {
                cout << name << " nao esta na Tardis." << endl;
            }
        } else if (command == "LISTAR") {
            if (tardis.empty()) {
                cout << "Nao ha ninguem na Tardis no momento." << endl;
            } else {
                for (const auto& person : tardis) {
                    cout << person << endl;
                }
            }
        } else if (command == "VERIFICAR") {
            if (tardis.find(name) != tardis.end()) {
                cout << name << " esta na Tardis." << endl;
            } else {
                cout << name << " nao esta na Tardis." << endl;
            }
        }
    }

    return 0;
}
