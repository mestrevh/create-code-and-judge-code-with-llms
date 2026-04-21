/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll X, Y;
    if (!(cin >> X >> Y)) return 0;

    ll g = gcd(X, Y);

    if (g < 2) {
        cout << -1 << endl;
        return 0;
    }

    ll max_prime_factor = -1;
    ll temp = g;

    for (ll i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            max_prime_factor = i;
            while (temp % i == 0) {
                temp /= i;
            }
        }
    }

    if (temp > 1) {
        max_prime_factor = temp;
    }

    if (max_prime_factor == -1) {
        cout << -1 << endl;
    } else {
        cout << max_prime_factor << endl;
    }

    return 0;
}