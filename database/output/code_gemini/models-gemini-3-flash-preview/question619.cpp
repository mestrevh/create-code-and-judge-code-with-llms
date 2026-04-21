/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool isSpecial(long long n) {
    if (n < 0) return false;
    if (n < 10) return true;
    int last = (int)(n % 10);
    long long first = n;
    while (first >= 10) {
        first /= 10;
    }
    return (int)first == last;
}

int bit[200010];
int n_size;

inline void update(int i, int delta) {
    for (; i <= n_size; i += i & -i)
        bit[i] += delta;
}

inline int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;
    n_size = N;

    vector<long long> A(N + 1);
    vector<bool> special(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (isSpecial(A[i])) {
            special[i] = true;
            update(i, 1);
        } else {
            special[i] = false;
        }
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R;
            cin >> L >> R;
            if (L > R) swap(L, R);
            cout << query(R) - query(L - 1) << "\n";
        } else if (type == 2) {
            int i;
            long long K;
            cin >> i >> K;
            if (i < 1 || i > N) continue;
            bool wasSpecial = special[i];
            bool nowSpecial = isSpecial(K);
            if (wasSpecial && !nowSpecial) {
                update(i, -1);
                special[i] = false;
            } else if (!wasSpecial && nowSpecial) {
                update(i, 1);
                special[i] = true;
            }
            A[i] = K;
        }
    }

    return 0;
}