/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int knightAwake, archerAwake, prisonerAwake, dogPresent;
    if (!(cin >> knightAwake >> archerAwake >> prisonerAwake >> dogPresent)) return 0;

    int fastAttack = (knightAwake == 0) ? 1 : 0;
    int spy = (knightAwake == 1 || archerAwake == 1) ? 1 : 0;
    int signal = (prisonerAwake == 1 && archerAwake == 0) ? 1 : 0;

    int rescue = 0;
    if (dogPresent == 1) {
        if (archerAwake == 0) rescue = 1;
    } else {
        if (prisonerAwake == 1 && knightAwake == 0 && archerAwake == 0) rescue = 1;
    }

    cout << fastAttack << ' ' << spy << ' ' << signal << ' ' << rescue;
    return 0;
}