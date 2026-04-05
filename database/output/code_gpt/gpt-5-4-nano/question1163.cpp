/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long P;
    if (!(cin >> P)) return 0;

    vector<string> nomes = {
        "", 
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

    if (P >= 1 && P <= 12) cout << nomes[(size_t)P];
    else cout << "Pokémon inválido no momento";
    return 0;
}