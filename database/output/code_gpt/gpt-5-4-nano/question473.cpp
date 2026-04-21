/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, m;
    double r;
    int approved = 0;

    while (cin >> p >> m >> r) {
        if (p < 0) break;
        double percP = (double)p / 50.0 * 100.0;
        double percM = (double)m / 35.0 * 100.0;
        if (percP >= 80.0 && percM >= 60.0 && r >= 7.0) approved++;
    }

    cout << approved << "\n";
    return 0;
}