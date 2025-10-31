/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
public:
    int life;
    vector<char> creatures;

    Player(int initialLife) : life(initialLife) {}
};

bool castSpell(Player &attacker, Player &defender, char spellType, int damage) {
    if (defender.creatures.empty()) {
        defender.life -= damage;
        return true;
    }

    for (size_t i = 0; i < defender.creatures.size(); i++) {
        if (defender.creatures[i] == spellType) {
            defender.creatures.erase(defender.creatures.begin() + i);
            return true;
        }
    }
    return false;
}

int main() {
    int life1, life2;
    cin >> life1 >> life2;
    
    Player player1(life1);
    Player player2(life2);
    
    string input;
    int turn = 0;

    while (cin >> input) {
        char type = input[0];
        char element = input[1];

        if (type == 'C') {
            player1.creatures.push_back(element);
        } else if (type == 'M') {
            int damage;
            cin >> damage;
            if (turn % 2 == 0) {
                castSpell(player1, player2, element, damage);
            } else {
                castSpell(player2, player1, element, damage);
            }
        }

        if (player1.life <= 0) {
            cout << "Jogador 2 ganhou!" << endl;
            return 0;
        }
        if (player2.life <= 0) {
            cout << "Jogador 1 ganhou!" << endl;
            return 0;
        }
        turn++;
    }
    return 0;
}
