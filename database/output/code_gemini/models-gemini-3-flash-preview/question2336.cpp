/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    map<int, multiset<long long>> garages;

    auto get_type = [](long long x) {
        if (x < 10) return -1;
        long long temp = x;
        while (temp >= 100) temp /= 10;
        return (int)temp;
    };

    while (cin >> cmd) {
        if (cmd == "VEICULO!!!") {
            long long id;
            if (!(cin >> id)) break;
            int type = get_type(id);
            if (type == 65 || type == 66 || type == 67 || type == 77 || type == 83 || type == 84) {
                garages[type].insert(id);
            } else {
                cout << "VERIFICAR TIPO DE VEICULO" << endl;
            }
        } else if (cmd == "VERIFICAR") {
            long long id;
            if (!(cin >> id)) break;
            int type = get_type(id);
            bool found = false;
            if (type != -1 && garages.count(type)) {
                if (garages[type].find(id) != garages[type].end()) {
                    found = true;
                }
            }
            if (found) {
                cout << "EXISTE" << endl;
            } else {
                cout << "AINDA NAO" << endl;
            }
        } else if (cmd == "IMPRIMIR") {
            int type;
            if (!(cin >> type)) break;
            if (garages.find(type) == garages.end() || garages[type].empty()) {
                cout << "A GARAGEM ESTA VAZIA :(" << endl;
            } else {
                bool first = true;
                for (long long x : garages[type]) {
                    if (!first) cout << " ";
                    cout << x;
                    first = false;
                }
                cout << endl;
            }
        } else if (cmd == "VENDER") {
            int type;
            if (!(cin >> type)) break;
            if (garages.find(type) == garages.end() || garages[type].empty()) {
                cout << "NADA REPETIDO POR ENQUANTO :)" << endl;
            } else {
                vector<long long> duplicates;
                vector<long long> uniques;
                auto& g = garages[type];
                for (auto it = g.begin(); it != g.end(); ) {
                    long long val = *it;
                    size_t count = g.count(val);
                    uniques.push_back(val);
                    if (count > 1) {
                        for (size_t i = 0; i < count - 1; ++i) {
                            duplicates.push_back(val);
                        }
                    }
                    advance(it, count);
                }
                if (duplicates.empty()) {
                    cout << "NADA REPETIDO POR ENQUANTO :)" << endl;
                } else {
                    for (size_t i = 0; i < duplicates.size(); ++i) {
                        cout << duplicates[i] << (i == duplicates.size() - 1 ? "" : " ");
                    }
                    cout << endl;
                    g.clear();
                    for (long long x : uniques) {
                        g.insert(x);
                    }
                }
            }
        }
    }

    return 0;
}