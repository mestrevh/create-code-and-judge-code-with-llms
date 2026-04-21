/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x;
    double sum = 0.0;
    const double CAP = 18.0;
    int cnt = 0;

    while (cin >> x) {
        if (sum + x > CAP + 1e-9) break;
        sum += x;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}