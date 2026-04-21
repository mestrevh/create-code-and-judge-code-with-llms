/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    if (!(cin >> P)) return 0;

    int W = 2 * P - 1;
    for (int i = 0; i < P; i++) {
        int left = P - 1 - i;
        int right = P - 1 + i;
        for (int j = 0; j < W; j++) {
            if (j == left || j == right) cout << '*';
            else if (j > left && j < right) cout << (i == 0 ? '.' : '-');
            else cout << '.';
        }
        if (i + 1 < P) cout << "\n";
    }
    return 0;
}