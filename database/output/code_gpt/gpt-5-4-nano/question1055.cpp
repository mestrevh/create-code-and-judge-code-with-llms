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

    vector<long double> diag(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long double x;
            cin >> x;
            if (i == j) diag[i] = x;
        }
    }

    long double sum = 0;
    for (auto v : diag) sum += v;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    cout << "tr(A) = ";
    for (int i = 0; i < n; i++) {
        if (i) cout << " + ";
        cout << "(" << (double)diag[i] << ")";
    }
    cout << " = " << (double)sum << "\n";
    return 0;
}