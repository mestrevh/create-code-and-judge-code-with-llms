/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int calcularHP(int level) {
    return floor(((2 * 90 + 9 + (25600 / 4)) * level / 100) + level + 10);
}

int calcularDefesa() {
    return floor((2 * 90 + 9 + (25600 / 4)) / 50);
}

int calcularDano(int level, int poder, int ataque, int defesa, double modifier) {
    return floor(((level * 0.4 + 2) * poder * ataque / defesa) / 50 + 2) * modifier;
}

int main() {
    string pokemon, ataque;
    int level;
    cin >> pokemon >> ataque >> level;

    if (pokemon != "Slowbro" && pokemon != "Dragonite") {
        cout << "Pokemon invalido";
        return 0;
    }
    if (ataque != "Surf" && ataque != "Flamethrower" && ataque != "Grass Knot") {
        cout << "Ataque invalido";
        return 0;
    }

    int hpMoltres = calcularHP(level);
    int defesaMoltres = calcularDefesa();
    int poder = (ataque == "Surf" || ataque == "Flamethrower") ? 90 : 120;
    int ataquePokemon = (pokemon == "Slowbro") ? 50 : 128;
    
    double modifier = 1.0;

    if (ataque == "Flamethrower") {
        modifier = 0.5; // Fogo contra planta
    } else if (ataque == "Grass Knot") {
        modifier = 2.0; // Planta contra agua
    }

    for (int i = 0; i < 4; ++i) {
        int dano = calcularDano((pokemon == "Slowbro") ? 30 : 40, poder, ataquePokemon, defesaMoltres, modifier);
        hpMoltres -= dano;
        if (hpMoltres <= 0) {
            cout << "Moltres morto";
            return 0;
        }
    }

    if (hpMoltres >= 10) {
        cout << "Moltres fugiu";
    } else {
        cout << "Moltres capturado";
    }
    
    return 0;
}
