/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

std::vector<int> bit;
int N_size;

bool is_special(long long n) {
    if (n < 0) {
        return false;
    }
    if (n < 10) {
        return true;
    }
    long long last_digit = n % 10;
    while (n >= 10) {
        n /= 10;
    }
    return n == last_digit;
}

void update(int idx, int delta) {
    for (; idx <= N_size; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int query_range(int l, int r) {
    if (l > r) {
        return 0;
    }
    return query(r) - query(l - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, Q;
    std::cin >> N >> Q;

    N_size = N;
    bit.assign(N + 1, 0);
    std::vector<long long> a(N + 1);

    for (int i = 1; i <= N; ++i) {
        std::cin >> a[i];
        if (is_special(a[i])) {
            update(i, 1);
        }
    }

    for (int q = 0; q < Q; ++q) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int l, r;
            std::cin >> l >> r;
            std::cout << query_range(l, r) << "\n";
        } else {
            int i;
            long long k;
            std::cin >> i >> k;

            bool old_is_special = is_special(a[i]);
            bool new_is_special = is_special(k);

            if (old_is_special && !new_is_special) {
                update(i, -1);
            } else if (!old_is_special && new_is_special) {
                update(i, 1);
            }
            
            a[i] = k;
        }
    }

    return 0;
}
