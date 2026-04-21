/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int CAP_P = 7;
    const double CAP_W = 560.0;

    int count = 0;
    double totalW = 0.0;
    double x;

    while (cin >> x) {
        if (x == 0.0) break;
        if (count == CAP_P) break;
        if (totalW + x > CAP_W + 1e-9) break;
        count++;
        totalW += x;
    }

    cout << count << "\n" << fixed << setprecision(1) << totalW << "\n";
    return 0;
}