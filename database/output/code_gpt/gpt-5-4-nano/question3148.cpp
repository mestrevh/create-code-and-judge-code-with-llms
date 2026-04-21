/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long P, N;
    if (!(cin >> P >> N)) return 0;

    double M, K;
    cin >> M >> K;

    double q = 1.0 - (M / 100.0) * K;

    double probOneFamilyNotInfected = pow(q, (double)P);
    double probAtLeastOneNotInfected = 1.0 - pow(probOneFamilyNotInfected, (double)N);

    double ans = probAtLeastOneNotInfected;
    cout.setf(std::ios::fixed);
    cout << setprecision(4) << ans << "\n";
    return 0;
}