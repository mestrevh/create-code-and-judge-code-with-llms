/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Fighter {
    string name;
    int g, s, c;
};

static inline bool betterGrappling(const Fighter& challenger, const Fighter& defender) {
    return challenger.g > defender.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    int bestEvent = 1;
    int bestKOs = -1;

    for (int ev = 1; ev <= N; ev++) {
        int x;
        cin >> x;

        int kos = 0;

        for (int i = 0; i < x; i++) {
            Fighter defender, challenger;
            cin >> defender.name >> defender.g >> defender.s >> defender.c;
            cin >> challenger.name >> challenger.g >> challenger.s >> challenger.c;

            string winner, method;

            int defG = defender.g, defS = defender.s;
            int chalG = challenger.g, chalS = challenger.s;
            int defC = defender.c, chalC = challenger.c;

            bool chalSub1 = (chalG > defS);
            bool chalKO2 = (chalS > defG);

            if (chalSub1) {
                winner = challenger.name;
                method = "submissao";
            } else if (chalKO2) {
                winner = challenger.name;
                method = "nocaute";
            } else if (chalG < defS) {
                winner = defender.name;
                method = "nocaute";
            } else if (chalS < defG) {
                winner = defender.name;
                method = "submissao";
            } else {
                if (defC != chalC) {
                    if (defC > chalC) {
                        winner = defender.name;
                        method = "decisao";
                    } else if (chalC > defC) {
                        winner = challenger.name;
                        method = "decisao";
                    } else {
                        winner = defender.name;
                        method = "decisao";
                    }
                } else {
                    winner = defender.name;
                    method = "decisao";
                }
            }

            if (method == "nocaute") kos++;

            cout << winner << " ganhou por " << method << "\n";
        }

        if (kos > bestKOs) {
            bestKOs = kos;
            bestEvent = ev;
        }
    }

    cout << "Melhor evento foi " << bestEvent << "\n";
    return 0;
}