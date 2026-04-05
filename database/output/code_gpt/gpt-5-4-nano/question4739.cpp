/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<string, vector<string>>> materias;
    string tipo;
    while (cin >> tipo) {
        if (tipo == "M") {
            string nome;
            if (!(cin >> nome)) break;
            materias.push({nome, vector<string>()});
        } else if (tipo == "A") {
            string atividade;
            cin >> atividade;
            if (!materias.empty()) materias.back().second.push_back(atividade);
        } else {
            string dummy;
            getline(cin, dummy);
        }
    }

    bool firstOut = true;
    while (!materias.empty()) {
        if (!firstOut) cout << "_________________\n\n";
        firstOut = false;

        auto &cur = materias.front();
        cout << "Materia: " << cur.first << "\n";
        for (auto &a : cur.second) cout << "    Atividade: " << a << "\n";

        auto &vec = materias.front().second;
        if (!vec.empty()) vec.pop_back();
        if (vec.empty()) materias.pop();
    }

    if (!firstOut) cout << "_________________\n\n";
    return 0;
}