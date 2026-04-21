/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 100000007;
const int MAXN = 1000005;

ll fact[MAXN];
ll invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * (ll)i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (ll)(i + 1)) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    string s;
    while (cin >> s && s != "0") {
        int freq[26] = {0};
        int n = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                freq[s[i] - 'a']++;
                n++;
            }
        }
        
        if (n == 0) {
            continue;
        }

        ll ans = fact[n];
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 1) {
                ans = (ans * invFact[freq[i]]) % MOD;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}