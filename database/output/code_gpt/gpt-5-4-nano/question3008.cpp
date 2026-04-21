/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y;
    if (!(cin >> X >> Y)) return 0;

    __int128 V = (__int128)X + (__int128)Y;
    auto ceil_div = [](__int128 a, __int128 b) -> __int128 {
        if (b < 0) a = -a, b = -b;
        if (a >= 0) return (a + b - 1) / b;
        return a / b; 
    };

    long long g = std::gcd(X, Y);

    long long a = X / g;
    long long b = Y / g;

    long long n = (a == 1 || b == 1) ? max(a, b) : 1;
    (void)n;

    __int128 num1 = (b - 1) * (__int128)X;
    __int128 den1 = a - 1;
    __int128 tmin;
    if (a == 1) {
        tmin = 0;
    } else {
        if (b == 1) tmin = 0;
        else tmin = ceil_div(num1, den1);
        if (tmin < 0) tmin = 0;
    }

    __int128 num2 = (a - 1) * (__int128)Y;
    __int128 den2 = b - 1;
    __int128 tmax;
    if (b == 1) {
        tmax = 0;
    } else {
        if (a == 1) tmax = 0;
        else tmax = num2 / den2;
        if (tmax < 0) tmax = -1;
    }

    __int128 T;
    if (a == 1 && b == 1) {
        cout << "0\n";
        return 0;
    }

    if (a != 1 && b != 1) {
        if (tmin > tmax) {
            cout << -1 << "\n";
            return 0;
        }
        T = tmin;
        __int128 S = T * (__int128)g;
        if (S == 0) {
            cout << -1 << "\n";
            return 0;
        }
        cout << (long long)S << "\n";
        return 0;
    }

    if (a == 1 && b != 1) {
        T = 0;
        __int128 S = T * (__int128)g;
        cout << (long long)S << "\n";
        return 0;
    }
    if (b == 1 && a != 1) {
        T = 0;
        __int128 S = T * (__int128)g;
        cout << (long long)S << "\n";
        return 0;
    }

    cout << -1 << "\n";
    return 0;
}