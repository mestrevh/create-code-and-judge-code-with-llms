/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long L;
    if (!(cin >> L)) return 0;

    long long P = 0;
    if (L >= 1 && L <= 20) {
        P = 20 + L * 3;
    } else if (L >= 21 && L <= 40) {
        P = 8000 + (L - 10) * (L - 10);
    } else if (L >= 41 && L <= 60) {
        P = 9000 + 5 * L;
    } else if (L >= 61 && L <= 80) {
        P = 9300 + 2 * L;
    } else if (L >= 81 && L <= 100) {
        P = 9500 + L;
    }

    cout << "Potencia de : " << P << " W";
    return 0;
}