/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double n;
    if (!(cin >> n)) return 0;

    long double pi = acosl(-1.0L);
    long double e = expl(1.0L);

    vector<long double> ans(10);

    ans[0] = n * n;
    ans[1] = (n + 1) * (n + 1) - n;
    ans[2] = sqrtl(n);
    ans[3] = cbrtl(n);
    ans[4] = powl(n, 0.5L);
    ans[5] = powl(n, 0.3L);
    ans[6] = pi / 2.0L;
    ans[7] = 1.0L / (n + 1.0L);
    ans[8] = logl(n);
    ans[9] = logl(n + e);

    cout << fixed << setprecision(16);
    cout << "i) " << (double)ans[0] << "\n";
    cout << "ii) " << (double)ans[1] << "\n";
    cout << "iii) " << (double)ans[2] << "\n";
    cout << "iv) " << (double)ans[3] << "\n";
    cout << "v) " << (double)ans[4] << "\n";
    cout << "vi) " << (double)ans[5] << "\n";
    cout << "vii) " << (double)ans[6] << "\n";
    cout << "viii) " << (double)ans[7] << "\n";
    cout << "ix) " << (double)ans[8] << "\n";
    cout << "x) " << (double)ans[9] << "\n";

    return 0;
}