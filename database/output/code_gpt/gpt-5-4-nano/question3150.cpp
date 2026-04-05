/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    if (!(cin >> A >> B >> C)) return 0;
    long long E;
    cin >> E;
    char obj;
    cin >> obj;

    vector<long long> enemies = {A, B, C};

    long long initE = E;
    double threshold = 0.3 * (double)initE;

    long long damageEnemy, damageEnergy;
    if (obj == 'C') {
        damageEnemy = 40;
        damageEnergy = 15;
    } else {
        damageEnemy = 50;
        damageEnergy = 20;
    }

    for (int i = 0; i < 3; i++) {
        long long hp = enemies[i];
        while (hp > 0) {
            if (E <= 0) {
                cout << "Que pena... Era um jovem tao promissor";
                return 0;
            }
            bool corona = ( (double)E < threshold );
            long long cost = corona ? damageEnergy * 2 : damageEnergy;
            hp -= damageEnemy;
            E -= cost;
        }
    }

    cout << "Eba! Pedro sobreviveu";
    return 0;
}