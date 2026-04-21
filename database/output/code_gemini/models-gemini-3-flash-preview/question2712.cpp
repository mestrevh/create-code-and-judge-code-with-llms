/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

string getEpoch(long long year) {
    if (year == 2019) return "Presente";
    if (year >= -3100 && year <= -30) return "Egito Antigo";
    if (year >= 794 && year <= 1185) return "Japao Feudal";
    if (year >= 2235) return "Brasil Futurista";
    return "Invalido";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    long long year;
    map<string, string> userPos;
    map<string, bool> hasTraveled;
    vector<string> userOrder;

    while (cin >> name >> year) {
        string current = (userPos.count(name) ? userPos[name] : "Presente");
        string target = getEpoch(year);

        if (target != "Invalido" && target != current) {
            cout << name << " foi de " << current << " para " << target << ".\n";
            userPos[name] = target;
            if (!hasTraveled[name]) {
                hasTraveled[name] = true;
                userOrder.push_back(name);
            }
        } else {
            cout << "Cuidado pra nao ficar preso no reino quantico, " << name << ".\n";
        }
    }

    string order[] = {"Presente", "Egito Antigo", "Japao Feudal", "Brasil Futurista"};
    bool firstHeader = true;

    for (int i = 0; i < 4; ++i) {
        list<string> occupants;
        for (const string& u : userOrder) {
            if (userPos[u] == order[i]) {
                occupants.push_back(u);
            }
        }

        if (!occupants.empty()) {
            if (firstHeader) {
                cout << "\n";
                firstHeader = false;
            }
            cout << order[i] << ":\n";
            for (const string& u : occupants) {
                cout << u << "\n";
            }
        }
    }

    return 0;
}