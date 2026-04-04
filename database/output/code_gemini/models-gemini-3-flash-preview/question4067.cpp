/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Pokemon {
    string name;
    long long factor2;
};

bool comparePokemons(const Pokemon& a, const Pokemon& b) {
    if (a.factor2 != b.factor2) {
        return a.factor2 > b.factor2;
    }
    return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string enemyName, enemyType;
    int enemyAtk, enemyDef;
    if (!(cin >> enemyName >> enemyType >> enemyAtk >> enemyDef)) return 0;

    int n;
    if (!(cin >> n)) return 0;

    vector<Pokemon> ashPokemons(n);
    for (int i = 0; i < n; ++i) {
        string pName, pType;
        int pAtk, pDef;
        cin >> pName >> pType >> pAtk >> pDef;

        bool advantage = false;
        if (pType == "agua" && enemyType == "fogo") advantage = true;
        else if (pType == "grama" && enemyType == "agua") advantage = true;
        else if (pType == "fogo" && enemyType == "grama") advantage = true;

        long long effectiveAtk2;
        if (advantage) {
            effectiveAtk2 = 3LL * pAtk;
        } else {
            effectiveAtk2 = 2LL * pAtk;
        }

        ashPokemons[i].name = pName;
        ashPokemons[i].factor2 = effectiveAtk2 - (2LL * enemyDef);
    }

    sort(ashPokemons.begin(), ashPokemons.end(), comparePokemons);

    for (int i = 0; i < (int)ashPokemons.size(); ++i) {
        cout << (i + 1) << ". " << ashPokemons[i].name << "\n";
    }

    return 0;
}