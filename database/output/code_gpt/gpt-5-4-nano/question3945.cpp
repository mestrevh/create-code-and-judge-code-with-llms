/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Pokemon {
    string name;
    string type;
    long long atk;
    long long def;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Pokemon> pokemons;
    pokemons.reserve(N);
    unordered_map<string, int> idxByName;
    unordered_map<string, vector<int>> idxByType;

    for (int i = 0; i < N; i++) {
        Pokemon p;
        cin >> p.name >> p.type >> p.atk >> p.def;
        pokemons.push_back(p);
        idxByName[p.name] = i;
        idxByType[p.type].push_back(i);
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "0") break;

        if (cmd == "list") {
            string x;
            cin >> x;
            auto it = idxByType.find(x);
            if (it != idxByType.end()) {
                for (int id : it->second) {
                    cout << "Pokemon 1: " << pokemons[id].name << "\n";
                    cout << " Ataque: " << pokemons[id].atk << "\n";
                    cout << " Defesa: " << pokemons[id].def << "\n";
                }
            }
        } else if (cmd == "luta") {
            string line;
            getline(cin, line);
            getline(cin, line);

            size_t pos = line.find(" vs ");
            string a = (pos == string::npos) ? line : line.substr(0, pos);
            string b = (pos == string::npos) ? "" : line.substr(pos + 4);

            int ia = idxByName[a];
            int ib = idxByName[b];

            long long left = pokemons[ia].atk - pokemons[ia].def;
            long long right = pokemons[ib].atk - pokemons[ib].def;

            if (left == right) {
                cout << "pareceque temos um empate\n";
            } else if (left > right) {
                cout << pokemons[ia].name << " deitou " << pokemons[ib].name << " na porrada\n";
            } else {
                cout << pokemons[ib].name << " deitou " << pokemons[ia].name << " na porrada\n";
            }
        }
    }

    return 0;
}