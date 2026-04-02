/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> countDigits(ll n) {
    vector<ll> counts(10, 0);
    if (n <= 0) return counts;
    for (ll m = 1; m <= n; m *= 10) {
        ll high = n / (m * 10);
        ll curr = (n / m) % 10;
        ll low = n % m;
        for (int d = 0; d < 10; ++d) {
            if (d > 0) {
                counts[d] += high * m;
                if (curr > d) {
                    counts[d] += m;
                } else if (curr == d) {
                    counts[d] += low + 1;
                }
            } else {
                if (high > 0) {
                    counts[0] += (high - 1) * m;
                    if (curr > 0) {
                        counts[0] += m;
                    } else {
                        counts[0] += low + 1;
                    }
                }
            }
        }
        if (n / 10 < m) break; 
    }
    return counts;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    while (cin >> a >> b && (a != 0 || b != 0)) {
        if (a > b) swap(a, b);
        vector<ll> resA = countDigits(a - 1);
        vector<ll> resB = countDigits(b);
        for (int i = 0; i < 10; ++i) {
            cout << resB[i] - resA[i] << (i == 9 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}