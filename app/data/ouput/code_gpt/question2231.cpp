/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string hero, flower;
    int bowserHealth;
    unordered_map<string, int> damage = {
        {"Mario", 0},
        {"Luigi", 0},
        {"FireFlower", 20},
        {"IceFlower", 30},
        {"BoomerangFlower", 40}
    };

    cin >> hero >> flower >> bowserHealth;

    int totalDamage = 4 * (damage[hero] + damage[flower]);

    if (totalDamage >= bowserHealth) {
        cout << hero << " conseguiu derrotar o Bowser e salvar a princesa Peach." << endl;
    } else {
        cout << "O Bowser conseguiu escapar." << endl;
    }

    return 0;
}
