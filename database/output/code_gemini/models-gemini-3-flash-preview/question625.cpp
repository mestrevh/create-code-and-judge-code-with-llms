/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

static int bit[100010];
static int A[100010];
static int n;

inline void update(int idx, int delta) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

inline int query(int idx) {
    int s = 0;
    for (; idx > 0; idx -= idx & -idx) {
        s += bit[idx];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        if ((A[i] & 1) == 0) {
            update(i, 1);
        }
    }

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int i, x;
            cin >> i >> x;
            bool was_even = ((A[i] & 1) == 0);
            bool is_even = ((x & 1) == 0);
            if (was_even != is_even) {
                update(i, is_even ? 1 : -1);
            }
            A[i] = x;
        } else if (op == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            int evens = query(r) - query(l - 1);
            cout << (r - l + 1) - evens << "\n";
        }
    }

    return 0;
}