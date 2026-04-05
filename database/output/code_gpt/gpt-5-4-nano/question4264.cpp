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
        cout << fixed << setprecision(0);
        long double x1 = 0, x2 = 0;
        if (b != 0) {
            x1 = -c / b;
            x2 = x1;
        }
        cout << "x1 = " << (long long) llround(x1) << "\n";
        cout << "x2 = " << (long long) llround(x2) << "\n";
        return 0;
    }

    long double delta = b * b - 4 * a * c;
    long double sqrt_delta = sqrtl(delta);
    long double x1 = (-b + sqrt_delta) / (2 * a);
    long double x2 = (-b - sqrt_delta) / (2 * a);

    cout << "x1 = " << (long long) llround(x1) << "\n";
    cout << "x2 = " << (long long) llround(x2) << "\n";
    return 0;
}