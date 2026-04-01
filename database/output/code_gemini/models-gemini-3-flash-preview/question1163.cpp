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
    if (!(cin >> p)) return 0;

    static const char* pokedex[] = {
        "Bulbasaur", 
        "Ivysaur", 
        "Venusaur",
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
        cout << pokedex[p - 1] << "\n";
    } else {
        cout << "Pokémon inválido no momento" << "\n";
    }

    return 0;
}