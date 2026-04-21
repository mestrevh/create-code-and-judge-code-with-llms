/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int I;
    if (!(cin >> I)) return 0;

    vector<string> order = {"Chandler", "Phoebe", "Joey", "Monica", "Ross"};
    unordered_map<string, string> typeToFriend = {
        {"Cafe", "Chandler"},
        {"Cha", "Phoebe"},
        {"Suco", "Ross"},
        {"Refrigerante", "Monica"},
        {"Cerveja", "Joey"}
    };

    unordered_map<string, vector<string>> pedidos;
    vector<string> others;

    for (int i = 0; i < I; i++) {
        string comida, tipo;
        cin >> comida >> tipo;
        auto it = typeToFriend.find(tipo);
        if (it != typeToFriend.end()) {
            pedidos[it->second].push_back(comida);
        } else {
            others.push_back(comida);
        }
    }

    bool anyFriends = false;
    for (auto &f : order) if (!pedidos[f].empty()) { anyFriends = true; break; }

    if (!anyFriends) {
        cout << "Nenhum dos meus amigos veio, não vou trabalhar hoje.\n";
        return 0;
    }

    for (size_t i = 0; i < order.size(); i++) {
        string f = order[i];
        cout << f;
        if (pedidos[f].empty()) {
            cout << " nao pediu nada.\n";
        } else {
            cout << ":\n";
            for (auto &c : pedidos[f]) cout << "-" << c << "\n";
        }
        if (i + 1 < order.size()) cout << "\n";
    }

    if (!others.empty()) {
        cout << "Outros Clientes:";
        for (auto &c : others) cout << "\n-" << c;
        cout << "\n";
    }

    return 0;
}