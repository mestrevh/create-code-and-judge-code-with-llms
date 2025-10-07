/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int I;
    cin >> I;
    cin.ignore();
    map<string, int> artistas;
    string artista;

    while (I--) {
        getline(cin, artista);
        artistas[artista]++;
    }

    vector<string> preferidos;
    int max_voto = 0;

    for (const auto& par : artistas) {
        if (par.second > max_voto) {
            max_voto = par.second;
            preferidos.clear();
            preferidos.push_back(par.first);
        } else if (par.second == max_voto) {
            preferidos.push_back(par.first);
        }
    }

    sort(preferidos.begin(), preferidos.end());

    if (preferidos.size() == 1) {
        cout << "As pessoas estao esperando por " << preferidos[0] << "." << endl;
    } else {
        cout << "Houve um empate entre: ";
        for (size_t i = 0; i < preferidos.size(); i++) {
            cout << preferidos[i];
            if (i < preferidos.size() - 1) cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
