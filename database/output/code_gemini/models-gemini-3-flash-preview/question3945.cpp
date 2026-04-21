/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Pokemon {
    string name;
    string type;
    int attack;
    int defense;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N) || N == 0) {
        return 0;
    }

    vector<Pokemon> pokes(N);
    unordered_map<string, Pokemon*> nameMap;
    unordered_map<string, vector<Pokemon*>> typeMap;

    for (int i = 0; i < N; ++i) {
        if (!(cin >> pokes[i].name >> pokes[i].type >> pokes[i].attack >> pokes[i].defense)) break;
        nameMap[pokes[i].name] = &pokes[i];
        typeMap[pokes[i].type].push_back(&pokes[i]);
    }

    string cmd;
    while (cin >> cmd && cmd != "0") {
        if (cmd == "list") {
            string t;
            cin >> t;
            auto it = typeMap.find(t);
            if (it != typeMap.end()) {
                int count = 1;
                for (auto p : it->second) {
                    cout << "Pokemon " << count++ << ": " << p->name << "\n";
                    cout << " Ataque: " << p->attack << "\n";
                    cout << " Defesa: " << p->defense << "\n";
                }
            }
        } else if (cmd == "luta") {
            string p1, vs, p2;
            if (cin >> p1 >> vs >> p2) {
                if (nameMap.count(p1) && nameMap.count(p2)) {
                    Pokemon* a = nameMap[p1];
                    Pokemon* b = nameMap[p2];
                    
                    int diffA = a->attack - b->defense;
                    int diffB = b->attack - a->defense;
                    
                    if (diffA > diffB) {
                        cout << a->name << " deitou " << b->name << " na porrada\n";
                    } else if (diffB > diffA) {
                        cout << b->name << " deitou " << a->name << " na porrada\n";
                    } else {
                        cout << "parece que temos um empate\n";
                    }
                }
            }
        }
    }

    return 0;
}