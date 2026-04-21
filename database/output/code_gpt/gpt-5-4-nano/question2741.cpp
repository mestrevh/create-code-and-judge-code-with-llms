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
    set<string> people;
    while (true) {
        string cmd;
        if (!(cin >> cmd)) break;
        if (cmd == "INSERIR") {
            string name;
            cin >> name;
            people.insert(name);
        } else if (cmd == "REMOVER") {
            string name;
            cin >> name;
            people.erase(name);
        } else if (cmd == "IMPRIMIR") {
            cout << "Atualmente trabalhando:\n";
            for (const auto& name : people) cout << name << "\n";
            cout << "\n";
        }
        getline(cin, line);
    }
    return 0;
}