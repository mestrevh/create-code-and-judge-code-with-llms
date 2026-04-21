/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    if (cin >> p) {
        vector<string> pokedex = {
            "Bulbassauro",
            "Ivyssauro",
            "Venossauro",
            "Charmander",
            "Charmeleon",
            "Charizard",
            "Squirtle",
            "Wartortle",
            "Blastoise",
            "Caterpie",
            "Metapod",
            "Butterfree"
        };

        if (p >= 1 && p <= 12) {
            cout << pokedex[p - 1] << endl;
        } else {
            cout << "Pokemon invalido no momento" << endl;
        }
    }

    return 0;
}