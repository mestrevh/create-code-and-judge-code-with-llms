/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int caseNum = 1;
    while ( (cin >> n >> m) ) {
        vector<long long> a(n+1), b(m+1);
        for (int i = 0; i <= n; i++) cin >> a[i];
        for (int i = 0; i <= m; i++) cin >> b[i];

        vector<long long> c(n + m + 1, 0);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                c[i + j] += a[i] * b[j];
            }
        }

        cout << "Caso #" << caseNum++ << ":";
        for (int k = 0; k <= n + m; k++) {
            cout << (k == 0 ? " " : " ") << c[k];
        }
        cout << "\n";
    }
    return 0;
}