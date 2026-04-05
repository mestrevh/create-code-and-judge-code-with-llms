/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static int tree[100005];
static int N, Q;

void update(int i, int val) {
    for (; i <= N; i += i & -i) {
        tree[i] ^= val;
    }
}

int query(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res ^= tree[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> Q)) return 0;

    string s;
    cin >> s;

    for (int i = 0; i < N; ++i) {
        update(i + 1, 1 << (s[i] - 'a'));
    }

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int L;
            char x;
            cin >> L >> x;
            int old_idx = s[L - 1] - 'a';
            int new_idx = x - 'a';
            update(L, (1 << old_idx) ^ (1 << new_idx));
            s[L - 1] = x;
        } else {
            int L, R;
            cin >> L >> R;
            if (L > R) swap(L, R);
            int res = query(R) ^ query(L - 1);
            if (__builtin_popcount((unsigned int)res) <= 1) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    return 0;
}