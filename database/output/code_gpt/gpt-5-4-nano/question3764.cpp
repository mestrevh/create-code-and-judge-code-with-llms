/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x;
    while (cin >> x) {
        if (x == -1) break;
        if (x < 7) cout << "ACIDA\n";
        else if (x > 7) cout << "BASICA\n";
        else cout << "NEUTRA\n";
    }
    return 0;
}