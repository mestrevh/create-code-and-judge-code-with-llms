/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DamageEvent {
    int damage;
    int time;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    vector<DamageEvent> events(X);
    for (int i = 0; i < X; ++i) {
        cin >> events[i].damage >> events[i].time;
    }

    int Y;
    if (!(cin >> Y)) Y = 0;

    sort(events.begin(), events.end(), [](const DamageEvent& a, const DamageEvent& b) {
        if (a.time != b.time) return a.time < b.time;
        return a.damage > b.damage;
    });

    int current_hp = 100;
    int last_time = 0;
    bool is_dead = false;

    for (int i = 0; i < X; ++i) {
        int delta_t = events[i].time - last_time;
        if (delta_t > 0) {
            current_hp += delta_t * Y;
            if (current_hp > 100) current_hp = 100;
        }
        
        current_hp -= events[i].damage;
        if (current_hp <= 0) {
            is_dead = true;
            break;
        }
        last_time = events[i].time;
    }

    if (is_dead) {
        cout << "Inimigo Morto" << endl;
    } else {
        cout << "Inimigo Vivo" << endl;
    }

    return 0;
}