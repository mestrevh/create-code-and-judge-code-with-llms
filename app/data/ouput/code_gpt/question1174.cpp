/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int P;
    cin >> P;
    vector<string> pokemons = {
        "Bulbassauro", "Ivyssauro", "Venossauro", "Charmander", "Charmeleon",
        "Charizard", "Squirtle", "Wartortle", "Blastoise", "Caterpie",
        "Metapod", "Butterfree"
    };

    if (P >= 1 && P <= 12) {
        cout << pokemons[P - 1] << endl;
    } else {
        cout << "Pokemon invalido no momento" << endl;
    }

    return 0;
}
