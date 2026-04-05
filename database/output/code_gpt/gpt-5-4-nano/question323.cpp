/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    bool first = true;
    while (cin >> N) {
        if (N == 0) break;

        if (!first) {}
        first = false;

        int m = N;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int val = min({i + 1, j + 1, m - i, m - j});
                cout << val;
                if (j + 1 < m) cout << ' ';
            }
            cout << "\n";
        }
        cout << "\n";
    }

    cout << "\n";
    return 0;
}