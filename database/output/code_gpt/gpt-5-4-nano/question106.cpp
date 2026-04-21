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
    bool firstCase = true;
    while (cin >> n) {
        if (n == 0) break;
        if (!firstCase) cout << "\n";
        firstCase = false;

        long long a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            long long val = (i == 0 ? 0 : (i == 1 ? 1 : (a + b)));
            if (i == 0) {
                cout << 0;
            } else if (i == 1) {
                cout << 1;
            } else {
                cout << val;
            }
            if (i + 1 < n) cout << " ";
            if (i >= 1) {
                long long c = a + b;
                a = b;
                b = c;
            }
        }
    }
    return 0;
}