/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lab;
    if (!(cin >> lab)) return 0;

    int x = 0;
    if (lab == 1) x = 28;
    else if (lab == 2) x = 26;
    else if (lab == 3) x = 15;
    else if (lab == 4) x = 20;
    else return 0;

    unordered_set<long long> used;
    vector<long long> available;

    for (int i = 0; i < x; i++) {
        int f;
        while (true) {
            if (!(cin >> f)) return 0;
            if (f == 0 || f == 1) break;
            cout << "Identificador invalido.\n";
        }

        long long id;
        while (true) {
            if (!(cin >> id)) return 0;
            if (used.find(id) != used.end()) {
                cout << "ID invalido. Nao pode haver pc's iguais\n";
                continue;
            }
            used.insert(id);
            break;
        }

        if (f == 0) available.push_back(id);
    }

    cout << "Quantidade de pessoas que podem utilizar os computadores: " << available.size() << "\n";
    if (available.empty()) {
        cout << "Sem computadores disponiveis nesse laboratorio.\n";
    } else {
        cout << "Lista de id's:\n";
        for (auto id : available) cout << id << "\n";
    }

    return 0;
}