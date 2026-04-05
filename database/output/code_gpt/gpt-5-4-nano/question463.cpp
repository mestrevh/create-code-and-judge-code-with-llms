/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long sarampo = 0, hepatite = 0, ambas = 0;
    int x;
    while (cin >> x) {
        if (x == 100) break;
        bool s = (x >= 3 && x <= 6);
        bool h = (x >= 5 && x <= 8);
        if (s) sarampo++;
        if (h) hepatite++;
        if (s && h) ambas++;
    }

    cout << sarampo << "\n" << hepatite << "\n" << ambas << "\n";
    return 0;
}