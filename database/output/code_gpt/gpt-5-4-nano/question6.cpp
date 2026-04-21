/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    if (a == 0) {
        cout << "NEESG";
        return 0;
    }

    long double delta = b * b - 4 * a * c;

    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    const long double EPS = 1e-12L;

    if (delta > EPS) {
        long double sdelta = sqrtl(delta);
        long double x1 = (-b + sdelta) / (2 * a);
        long double x2 = (-b - sdelta) / (2 * a);
        cout << (double)x1 << "\n" << (double)x2;
    } else if (delta < -EPS) {
        cout << "NRR";
    } else {
        long double x = (-b) / (2 * a);
        cout << (double)x << "\n" << (double)x;
    }

    return 0;
}