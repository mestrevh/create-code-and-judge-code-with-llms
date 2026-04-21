/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128_t int128;

ll solve_f(ll T, ll K, ll limit) {
    ll res = 0;
    ll term = 1;
    for (ll i = 1; i <= K; ++i) {
        if (T < i) break;
        int128 next_term = (int128)term * (T - i + 1) / i;
        if (next_term >= limit) return limit;
        term = (ll)next_term;
        res += term;
        if (res >= limit) return limit;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, K;
    if (!(cin >> N >> K)) return 0;

    if (K > 30) K = 30;

    ll low = 1, high = N, ans = N;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (solve_f(mid, K, N) >= N) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}