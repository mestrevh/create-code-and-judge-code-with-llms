/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, int val) {
        for (; i <= n; i += i & -i) tree[i] += val;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

ll count_inversions(int n, const vector<int>& v) {
    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());
    BIT bit(sorted_v.size());
    ll inv = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin() + 1;
        inv += (i - bit.query(pos));
        bit.update(pos, 1);
    }
    return inv;
}

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd_val = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd_val;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    extended_gcd(a, m, x, y);
    return (x % m + m) % m;
}

ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int find_set(vector<int>& parent, int i) {
    int root = i;
    while (parent[root] != root) root = parent[root];
    while (parent[i] != root) {
        int next = parent[i];
        parent[i] = root;
        i = next;
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll m;
    if (!(cin >> n >> m)) return 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll inv = count_inversions(n, v);
    ll s = inv % m;

    if (s == 0) {
        for (int i = 0; i < n; i++) {
            cout << v[i] % m << "\n";
        }
    } else {
        ll g = get_gcd(s, m);
        ll m_prime = m / g;
        ll s_prime = s / g;
        ll inv_s = modInverse(s_prime, m_prime);

        vector<int> parent(m);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++) {
            ll p = v[i] % m;
            ll rem = p % g;
            ll k = p / g;
            ll idx = (1LL * k * inv_s) % m_prime;

            int actual_idx = find_set(parent, (int)(rem * m_prime + idx));
            int logical_idx = actual_idx - (int)(rem * m_prime);

            ll new_k = (1LL * logical_idx * s_prime) % m_prime;
            ll final_pos = rem + new_k * g;

            cout << final_pos << "\n";

            int next_logical_idx = (logical_idx + 1) % (int)m_prime;
            parent[actual_idx] = find_set(parent, (int)(rem * m_prime + next_logical_idx));
        }
    }

    return 0;
}