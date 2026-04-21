/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int comp, edu;
    int compGoals = 0, eduGoals = 0;

    for (int i = 0; i < 10; i++) {
        int x;
        if (!(cin >> x)) return 0;
        if (i % 2 == 0) {
            if (x == 1) compGoals++;
        } else {
            if (x == 1) eduGoals++;
        }

        int compTaken = (i % 2 == 0) ? (i / 2 + 1) : (i / 2 + 1);
        int eduTaken = (i % 2 == 0) ? (i / 2) : (i / 2 + 1);

        int compRemaining = 5 - compTaken;
        int eduRemaining = 5 - eduTaken;

        if (compGoals > eduGoals + eduRemaining) {
            cout << "COMPUTACAO.RAR\n";
            return 0;
        }
        if (eduGoals > compGoals + compRemaining) {
            cout << "EDUCACAO FISICA\n";
            return 0;
        }
    }

    if (compGoals > eduGoals) {
        cout << "COMPUTACAO.RAR\n";
        return 0;
    }
    if (eduGoals > compGoals) {
        cout << "EDUCACAO FISICA\n";
        return 0;
    }

    while (true) {
        if (!(cin >> comp)) return 0;
        if (comp == 1) compGoals++;

        if (!(cin >> edu)) return 0;
        if (edu == 1) eduGoals++;

        if (compGoals > eduGoals) {
            cout << "COMPUTACAO.RAR\n";
            return 0;
        }
        if (eduGoals > compGoals) {
            cout << "EDUCACAO FISICA\n";
            return 0;
        }
    }
}