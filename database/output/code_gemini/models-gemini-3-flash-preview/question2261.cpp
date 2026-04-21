/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    string dummy;
    getline(cin, dummy);

    map<string, int> char_map;
    char_map["Coragem"] = 0;
    char_map["Determinacao"] = 0;
    char_map["Conviccao"] = 0;
    char_map["Ambicao"] = 1;
    char_map["Astucia"] = 1;
    char_map["Expertise"] = 1;
    char_map["Analise"] = 2;
    char_map["Suporte"] = 2;
    char_map["Tecnica"] = 2;
    char_map["Agilidade"] = 3;
    char_map["Inteligencia"] = 3;
    char_map["Destreza"] = 3;
    char_map["Experiencia"] = 4;
    char_map["Perspicacia"] = 4;
    char_map["Pericia"] = 4;

    vector<string> contracts[5];
    bool any_contract = false;

    for (int i = 0; i < n; ++i) {
        string line;
        if (!getline(cin, line)) break;
        if (line.empty()) continue;

        stringstream ss(line);
        string name, characteristic;
        if (ss >> name) {
            if (ss >> characteristic) {
                if (char_map.count(characteristic)) {
                    contracts[char_map[characteristic]].push_back(name);
                    any_contract = true;
                }
            }
        }
    }

    if (!any_contract) {
        cout << "Nao havera Jounins forte esse ano" << endl;
    } else {
        const char* animals[] = {"Sapos:", "Cobras:", "Lesmas:", "Macacos:", "Caes:"};
        for (int i = 0; i < 5; ++i) {
            cout << animals[i] << "\n";
            for (const string& ninja_name : contracts[i]) {
                cout << "- " << ninja_name << "\n";
            }
        }
    }

    return 0;
}