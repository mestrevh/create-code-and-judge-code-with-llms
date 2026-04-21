/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    long long initial_energy;
    if (!(cin >> initial_energy)) return 0;

    char weapon;
    if (!(cin >> weapon)) return 0;

    long long dmg, cost;
    if (weapon == 'C') {
        dmg = 40;
        cost = 15;
    } else {
        dmg = 50;
        cost = 20;
    }

    long long current_energy = initial_energy;
    long long enemies[3] = {a, b, c};
    bool survived = true;

    for (int i = 0; i < 3; ++i) {
        if (enemies[i] <= 0) continue;
        
        long long hits = (enemies[i] + dmg - 1) / dmg;
        for (long long h = 0; h < hits; ++h) {
            long long current_cost = cost;
            
            if (10 * current_energy < 3 * initial_energy) {
                current_cost *= 2;
            }
            
            current_energy -= current_cost;
            
            if (current_energy <= 0) {
                survived = false;
                break;
            }
        }
        if (!survived) break;
    }

    if (survived) {
        cout << "Eba! Pedro sobreviveu" << endl;
    } else {
        cout << "Que pena... Era um jovem tao promissor" << endl;
    }

    return 0;
}