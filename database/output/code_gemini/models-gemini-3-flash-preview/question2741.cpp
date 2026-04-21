/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <iterator>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    list<string> workers;
    unordered_map<string, list<string>::iterator> worker_map;

    while (cin >> cmd) {
        if (cmd == "INSERIR") {
            string name;
            cin >> name;
            if (worker_map.find(name) == worker_map.end()) {
                workers.push_back(name);
                worker_map[name] = prev(workers.end());
            }
        } else if (cmd == "REMOVER") {
            string name;
            cin >> name;
            auto it = worker_map.find(name);
            if (it != worker_map.end()) {
                workers.erase(it->second);
                worker_map.erase(it);
            }
        } else if (cmd == "IMPRIMIR") {
            cout << "Atualmente trabalhando:\n";
            for (const auto& w : workers) {
                cout << w << "\n";
            }
            cout << "\n";
        }
    }

    return 0;
}