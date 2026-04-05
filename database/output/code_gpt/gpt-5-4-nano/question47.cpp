/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n < 1000 || n > 9999) break;

        int a = n / 100;
        int b = n % 100;
        int s = a + b;
        long long sq = 1LL * s * s;

        if (sq == n) cout << "propriedade do 3025!";
        else cout << "numero comum";
        cout << "\n";
    }
    return 0;
}