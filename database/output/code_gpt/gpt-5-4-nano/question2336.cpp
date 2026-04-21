/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, string> garageType = {
        {67, "Carro"},
        {65, "Avião"},
        {77, "Moto"},
        {66, "Bicicleta"},
        {84, "Tanque"},
        {83, "Submarino"}
    };

    auto isValidType = [&](int type) -> bool {
        return garageType.find(type) != garageType.end();
    };

    unordered_map<int, vector<string>> models;
    string cmd;
    while (cin >> cmd) {
        long long Ill;
        if (cmd == "VERIFICAR" || cmd == "IMPRIMIR" || cmd == "VEICULO!!!" || cmd == "VENDER") {
            if (!(cin >> Ill)) break;
        }

        if (cmd == "VERIFICAR") {
            int type = (int)(Ill / 100);
            long long model = Ill % 1000000000LL;
            string s = to_string(Ill);
            if (!s.empty()) type = (int)s[0];

            int garageKey = type;
            if (!isValidType(garageKey)) {
                cout << "AINDA NAO\n";
                continue;
            }

            auto &v = models[garageKey];
            string needle = s;
            bool ok = false;
            for (const auto &x : v) {
                if (x == needle) { ok = true; break; }
            }
            cout << (ok ? "EXISTE" : "AINDA NAO") << "\n";
        } else if (cmd == "IMPRIMIR") {
            int type = (int)(Ill / 100);
            string s = to_string(Ill);
            if (!s.empty()) type = (int)s[0];
            int garageKey = type;

            if (!isValidType(garageKey)) {
                cout << "A GARAGEM ESTA VAZIA :(\n";
                continue;
            }

            auto &v = models[garageKey];
            if (v.empty()) {
                cout << "A GARAGEM ESTA VAZIA :(\n";
                continue;
            }
            vector<string> sorted = v;
            sort(sorted.begin(), sorted.end(), [](const string& a, const string& b){
                if (a.size() != b.size()) return a.size() < b.size();
                return a < b;
            });
            for (int i = 0; i < (int)sorted.size(); i++) {
                if (i) cout << ' ';
                cout << sorted[i];
            }
            cout << "\n";
        } else if (cmd == "VEICULO!!!") {
            string s;
            cin >> s;
            if (s.empty()) continue;
            int typeChar = (unsigned char)s[0];
            int garageKey = typeChar;

            if (!isValidType(garageKey)) {
                cout << "VERIFICAR TIPO DE VEICULO\n";
                continue;
            }
            models[garageKey].push_back(s);
        } else if (cmd == "VENDER") {
            string s;
            s = to_string(Ill);
            int typeChar = (unsigned char)s[0];
            int garageKey = typeChar;

            if (!isValidType(garageKey)) {
                cout << "NADA REPETIDO POR ENQUANTO :)\n";
                continue;
            }

            auto &v = models[garageKey];
            unordered_set<string> seen;
            unordered_set<string> printed;
            vector<string> reps;

            for (const auto &x : v) {
                if (seen.count(x)) {
                    if (!printed.count(x)) {
                        printed.insert(x);
                        reps.push_back(x);
                    }
                } else {
                    seen.insert(x);
                }
            }

            if (reps.empty()) {
                cout << "NADA REPETIDO POR ENQUANTO :)\n";
                continue;
            }

            sort(reps.begin(), reps.end(), [](const string& a, const string& b){
                if (a.size() != b.size()) return a.size() < b.size();
                return a < b;
            });

            for (int i = 0; i < (int)reps.size(); i++) {
                if (i) cout << ' ';
                cout << reps[i];
            }
            cout << "\n";

            unordered_set<string> repSet(reps.begin(), reps.end());
            vector<string> newV;
            newV.reserve(v.size());
            for (const auto &x : v) {
                if (!repSet.count(x)) newV.push_back(x);
            }
            v.swap(newV);
        }
    }

    return 0;
}