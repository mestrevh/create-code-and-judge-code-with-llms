/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;

    unordered_set<string> enemies;
    {
        string token;
        stringstream ss(line);
        while (ss >> token) enemies.insert(token);
    }

    set<string> inside;
    auto isEnemy = [&](const string& name) -> bool {
        return enemies.find(name) != enemies.end();
    };

    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        string cmd, name;
        {
            stringstream ss(line);
            ss >> cmd;
            if (!(cmd == "LISTAR")) ss >> name;
        }

        if (cmd == "ENTRAR") {
            if (isEnemy(name)) {
                cout << "Doctor o vilao " << name << " tentou entrar na Tardis." << "\n";
            } else {
                inside.insert(name);
                cout << name << " entrou na Tardis." << "\n";
            }
        } else if (cmd == "SAIR") {
            auto it = inside.find(name);
            if (it == inside.end()) {
                cout << name << " nao esta na Tardis." << "\n";
            } else {
                inside.erase(it);
                cout << name << " saiu da Tardis." << "\n";
            }
        } else if (cmd == "LISTAR") {
            if (inside.empty()) {
                cout << "Nao ha ninguem na Tardis no momento." << "\n";
            } else {
                for (auto &p : inside) cout << p << "\n";
            }
        } else if (cmd == "VERIFICAR") {
            if (inside.find(name) != inside.end()) cout << name << " esta na Tardis." << "\n";
            else cout << name << " nao esta na Tardis." << "\n";
        }
    }

    return 0;
}