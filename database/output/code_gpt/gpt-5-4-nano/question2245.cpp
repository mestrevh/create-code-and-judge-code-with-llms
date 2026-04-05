/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Runner {
    array<string,4> dir;
    array<long long,4> dist;
    bool dead = false;
    long long total = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto readRunner = [&]() -> Runner {
        Runner r;
        for (int i = 0; i < 4; i++) {
            if (!(cin >> r.dir[i] >> r.dist[i])) {
                r.dir[i] = "";
                r.dist[i] = 0;
            }
        }
        r.total = 0;
        for (int i = 0; i < 4; i++) r.total += r.dist[i];

        int leftStreak = 0;
        for (int i = 0; i < 4; i++) {
            if (r.dir[i] == "Esquerda") {
                leftStreak++;
                if (leftStreak == 3) r.dead = true;
            } else {
                leftStreak = 0;
            }
        }
        return r;
    };

    Runner mario = readRunner();
    Runner yoshi = readRunner();
    Runner toad = readRunner();

    bool anyDead = mario.dead || yoshi.dead || toad.dead;

    if (mario.dead) cout << "Mario caiu em um buraco negro.\n";
    if (yoshi.dead) cout << "Yoshi caiu em um buraco negro.\n";
    if (toad.dead) cout << "Toad caiu em um buraco negro.\n";

    long long best = (1LL<<62);
    string winner;

    if (!mario.dead && mario.total < best) { best = mario.total; winner = "Mario"; }
    if (!yoshi.dead && yoshi.total < best) { best = yoshi.total; winner = "Yoshi"; }
    if (!toad.dead && toad.total < best) { best = toad.total; winner = "Toad"; }

    cout << winner << " venceu a corrida!\n";
    return 0;
}