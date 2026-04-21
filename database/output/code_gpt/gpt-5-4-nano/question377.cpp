/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome1, nome2;
    long long p1, s1, g1, p2, s2, g2;
    if (!(cin >> nome1)) return 0;
    cin >> p1 >> s1 >> g1;
    cin >> nome2;
    cin >> p2 >> s2 >> g2;

    string winner;
    if (p1 != p2) {
        winner = (p1 > p2) ? nome1 : nome2;
    } else if (s1 != s2) {
        winner = (s1 > s2) ? nome1 : nome2;
    } else if (g1 != g2) {
        winner = (g1 > g2) ? nome1 : nome2;
    } else {
        cout << "EMPATE";
        return 0;
    }

    for (char &c : winner) c = (char)tolower((unsigned char)c);
    cout << winner;
    return 0;
}