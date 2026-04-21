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
    if (!(cin >> n)) return 0;

    long long total = 0;

    for (int i = 0; i < n; i++) {
        int dots = n - 1 - i;
        int cells = 2 * i + 1;
        for (int j = 0; j < dots; j++) cout << '.';

        for (int j = 0; j < cells; j++) {
            cout << '&';
            if (j != cells - 1) {
                if (j % 2 == 0) {
                    cout << '-';
                    total += 50;
                }
            }
        }
        cout << '\n';
    }

    int baseCells = 2 * n + 1;
    for (int j = 0; j < baseCells; j++) cout << '#';
    cout << '\n';

    total += 200LL * (n * n);
    total += 50LL * (n * n - 1);
    total += 100LL * baseCells;

    cout << "O valor total foi: " << total;
    return 0;
}