/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Card {
    int health, power;
    vector<int> attackable;
};

int main() {
    int n;
    cin >> n;
    vector<Card> entity(n), x(n);

    for (int i = 0; i < n; i++) {
        cin >> entity[i].health >> entity[i].power;
        int k;
        cin >> k;
        entity[i].attackable.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> entity[i].attackable[j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> x[i].health >> x[i].power;
        int k;
        cin >> k;
        x[i].attackable.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> x[i].attackable[j];
        }
    }

    int turns = 0;
    bool entity_wins = true;

    while (true) {
        turns++;
        vector<int> e_health(n), x_health(n);
        
        for (int i = 0; i < n; i++) e_health[i] = entity[i].health;
        for (int i = 0; i < n; i++) x_health[i] = x[i].health;
        
        // Entity attacks
        for (int i = 0; i < n; i++) {
            if (e_health[i] > 0) {
                int total_power = entity[i].power;
                int count = entity[i].attackable.size();
                for (int j : entity[i].attackable) {
                    if (x_health[j] > 0) {
                        int damage = total_power / count;
                        x_health[j] -= damage;
                        total_power -= damage;
                    }
                }
            }
        }

        bool x_alive = any_of(x_health.begin(), x_health.end(), [](int h) { return h > 0; });
        if (!x_alive) break;

        // X attacks
        for (int i = 0; i < n; i++) {
            if (x_health[i] > 0) {
                int total_power = x[i].power;
                int count = x[i].attackable.size();
                for (int j : x[i].attackable) {
                    if (e_health[j] > 0) {
                        int damage = total_power / count;
                        e_health[j] -= damage;
                        total_power -= damage;
                    }
                }
            }
        }

        bool e_alive = any_of(e_health.begin(), e_health.end(), [](int h) { return h > 0; });
        if (!e_alive) {
            entity_wins = false;
            break;
        }
    }

    cout << (entity_wins ? "Entity" : "X") << " wins in " << turns << " turns" << endl;
    return 0;
}
