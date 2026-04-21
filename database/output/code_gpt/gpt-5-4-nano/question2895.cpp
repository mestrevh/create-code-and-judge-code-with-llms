/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    if (!(cin >> x >> y)) return 0;

    long long ax, ay;
    string name;

    long long bestDist = -1;
    string bestName;

    while (cin >> ax >> ay >> name) {
        long long dx = x - ax;
        long long dy = y - ay;
        long long dist2 = dx * dx + dy * dy;

        if (bestDist == -1 || dist2 < bestDist) {
            bestDist = dist2;
            bestName = name;
        }
    }

    if (bestDist != -1 && bestDist < 100) {
        cout << "O aluno novo é mais parecido com " << bestName << "\n";
    } else {
        cout << "Aparentemente ele não é tão chato assim\n";
    }

    return 0;
}