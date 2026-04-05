/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

typedef long long ll;

ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        ll tmp = a;
        a = b;
        b = tmp;
    }
    return a;
}

ll power(ll base, ll exp) {
    ll res = 1;
    ll mod = 1000000007;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    ll g = 0;
    ll f = 1;
    ll mod = 1000000007;

    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        if (i == 0) {
            g = val;
        } else {
            g = get_gcd(g, val);
        }
        f = (f * val) % mod;
    }

    cout << power(f, g) << "\n";

    return 0;
}