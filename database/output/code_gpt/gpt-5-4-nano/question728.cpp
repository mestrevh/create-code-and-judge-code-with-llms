/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

double velkmh(double V0, double A, double T) {
    double V = V0 + A * T;
    return V * 3.6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double V0[3], A[3], T[3];
    for (int i = 0; i < 3; i++) {
        if (!(cin >> V0[i] >> A[i] >> T[i])) return 0;
    }

    double ans = min({velkmh(V0[0], A[0], T[0]), velkmh(V0[1], A[1], T[1]), velkmh(V0[2], A[2], T[2])});
    cout.setf(std::ios::fixed);
    cout << setprecision(1) << ans << "\n";
    return 0;
}