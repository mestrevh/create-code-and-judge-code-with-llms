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
    long double R;
    if (!(cin >> N >> R)) return 0;

    long double pi = acosl(-1.0L);
    long double per = N * 2.0L * R * sinl(pi / N);

    cout << fixed << setprecision(2) << (double)per << "\n";
    return 0;
}