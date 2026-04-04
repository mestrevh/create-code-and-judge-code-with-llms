/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Club {
    string name;
    int money;
    char focus;
    int id;
    struct PlayerRef {
        string n, c;
    };
    vector<PlayerRef> players;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Club> clubs;
    for (int i = 0; i < n; ++i) {
        string name;
        if (!(cin >> name)) break;
        if (name == "Vasco") {
            cout << "Vasco nao tem salvacao, tomou 3 pro vitoria em casa" << "\n";
            continue;
        }
        int m;
        char f;
        cin >> m >> f;
        clubs.push_back({name, m, f, (int)clubs.size(), {}});
    }

    int n2;
    if (!(cin >> n2)) return 0;

    for (int i = 0; i < n2; ++i) {
        string pn, pc;
        int pa, pd, pcost;
        cin >> pn >> pc >> pa >> pd >> pcost;

        char ptype = (pa >= pd) ? 'A' : 'D';
        int best = -1;

        for (int j = 0; j < (int)clubs.size(); ++j) {
            if (clubs[j].money >= pcost) {
                if (best == -1) {
                    best = j;
                } else {
                    bool curMatch = (clubs[j].focus == ptype);
                    bool bestMatch = (clubs[best].focus == ptype);

                    if (curMatch && !bestMatch) {
                        best = j;
                    } else if (curMatch == bestMatch) {
                        if (clubs[j].money > clubs[best].money) {
                            best = j;
                        } else if (clubs[j].money == clubs[best].money) {
                            if (clubs[j].id < clubs[best].id) {
                                best = j;
                            }
                        }
                    }
                }
            }
        }

        if (best != -1) {
            clubs[best].money -= pcost;
            clubs[best].players.push_back({pn, pc});
            cout << pn << " eh do " << clubs[best].name << "\n";
        } else {
            cout << pn << " ta muito caro" << "\n";
        }
    }

    for (int i = 0; i < (int)clubs.size(); ++i) {
        cout << "\nSituacao " << clubs[i].name << "\n";
        cout << "Dinheiro restante = " << clubs[i].money << "\n";
        cout << "Num de Jogadores = " << clubs[i].players.size() << "\n";
        for (const auto& p : clubs[i].players) {
            cout << p.n << " " << p.c << "\n";
        }
    }

    return 0;
}