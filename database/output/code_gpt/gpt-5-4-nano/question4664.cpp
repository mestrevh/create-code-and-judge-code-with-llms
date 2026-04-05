/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long b, m, v;
    if (!(cin >> b >> m >> v)) return 0;
    char c;
    long long e;
    cin >> c >> e;

    long long total = b + m + v;

    auto printLine = [&](const string& s) {
        cout << s << "\n";
    };

    if (e <= 0 || e > total) {
        printLine("You pensa que me engana, vou te mostrar a glocada de 30!");
        return 0;
    }

    long long diff = total - e;

    if (c == 'B') {
        if (diff % 7 == 0) printLine("Parabens pobre, ganhou uma box of good good");
        else printLine("Not my problema");
    } else if (c == 'M') {
        bool win = (diff % 3 == 0 && diff % 2 != 0) || (diff % 8 == 0);
        if (win) printLine("Acui, uma box of good good for you, alright?");
        else printLine("Deixei sua box of good good la em Xique-Xique Bahia");
    } else if (c == 'V') {
        bool win = (diff % 2 != 0) || (diff % 5 == 0);
        if (win) printLine("HEEHEE, good good for you");
        else printLine("Sem good good for you, alright?");
    } else {
        printLine("Ta querendo enganar quem, POBRE?!");
    }

    return 0;
}