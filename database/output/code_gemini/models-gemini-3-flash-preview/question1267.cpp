/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> grif, son, cor, luf;

    for (int i = 0; i < n; ++i) {
        string name, trait;
        cin >> name;
        getline(cin >> ws, trait);

        if (trait == "coragem" || trait == "determinacao") {
            grif.push_back(name);
        } else if (trait == "astucia" || trait == "ambicao") {
            son.push_back(name);
        } else if (trait == "inteligencia" || trait == "forca de vontade") {
            cor.push_back(name);
        } else if (trait == "lealdade" || trait == "companheirismo") {
            luf.push_back(name);
        }
    }

    cout << "Grifinoria:" << "\n";
    for (const auto& s : grif) {
        cout << s << "\n";
    }

    cout << "Sonserina:" << "\n";
    for (const auto& s : son) {
        cout << s << "\n";
    }

    cout << "Corvinal:" << "\n";
    for (const auto& s : cor) {
        cout << s << "\n";
    }

    cout << "Lufa-lufa:" << "\n";
    for (const auto& s : luf) {
        cout << s << "\n";
    }

    return 0;
}