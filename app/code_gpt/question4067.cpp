/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Pokemon {
    string name;
    string type;
    int attack;
    int defense;
    double advantageFactor;

    void calculateAdvantage(const string &enemyType, int enemyAttack, int enemyDefense) {
        advantageFactor = attack - enemyDefense;
        if ((type == "agua" && enemyType == "fogo") ||
            (type == "grama" && enemyType == "agua") ||
            (type == "fogo" && enemyType == "grama")) {
            advantageFactor *= 1.5;
        }
    }
};

bool comparePokemons(const Pokemon &a, const Pokemon &b) {
    if (a.advantageFactor == b.advantageFactor)
        return a.name < b.name;
    return a.advantageFactor > b.advantageFactor;
}

int main() {
    string enemyName, enemyType;
    int enemyAttack, enemyDefense;
    
    cin >> enemyName >> enemyType >> enemyAttack >> enemyDefense;
    
    int n;
    cin >> n;
    vector<Pokemon> pokemons(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> pokemons[i].name >> pokemons[i].type >> pokemons[i].attack >> pokemons[i].defense;
        pokemons[i].calculateAdvantage(enemyType, enemyAttack, enemyDefense);
    }
    
    sort(pokemons.begin(), pokemons.end(), comparePokemons);
    
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". " << pokemons[i].name << endl;
    }
    
    return 0;
}
