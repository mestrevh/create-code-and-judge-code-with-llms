/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll get_lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a / get_gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll a[4];
        ll max_v = 0;
        for (int i = 0; i < 4; i++) {
            if (!(cin >> a[i])) break;
            if (a[i] > max_v) max_v = a[i];
        }
        sort(a, a + 4);
        ll l = get_lcm(a[2], a[3]);
        ll res = l;
        while (res <= max_v) {
            res += l;
        }
        cout << res << "\n";
    }

    return 0;
}