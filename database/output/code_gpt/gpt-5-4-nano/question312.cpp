/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    if (!(cin >> x)) return 0;

    if (x < 0.0L || x > 100.0L) {
        cout << "Fora de intervalo";
    } else if (x >= 0.0L && x <= 25.0L) {
        cout << "Intervalo [0,25]";
    } else if (x > 25.0L && x <= 50.0L) {
        cout << "Intervalo (25,50]";
    } else if (x > 50.0L && x <= 75.0L) {
        cout << "Intervalo (50,75]";
    } else {
        cout << "Intervalo (75,100]";
    }

    return 0;
}