/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    if (!(cin >> A)) return 0;
    if (!(cin >> B)) return 0;

    int n = (int)A.size(), m = (int)B.size();
    if ((n == 1 && A[0] == '0') || (m == 1 && B[0] == '0')) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) a[i] = A[n - 1 - i] - '0';
    for (int i = 0; i < m; i++) b[i] = B[m - 1 - i] - '0';

    vector<long long> res(n + m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += 1LL * a[i] * b[j];
        }
    }

    for (int i = 0; i < (int)res.size() - 1; i++) {
        if (res[i] >= 10) {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }

    int i = (int)res.size() - 1;
    while (i > 0 && res[i] == 0) i--;
    for (; i >= 0; i--) cout << res[i];
    cout << "\n";
    return 0;
}