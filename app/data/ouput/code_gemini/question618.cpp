/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int N, Q;
std::string S;
std::vector<int> bit;

int get_mask(char c) {
    return 1 << (c - 'a');
}

void update(int idx, int val) {
    for (; idx <= N; idx += idx & -idx) {
        bit[idx] ^= val;
    }
}

int query(int idx) {
    int xor_sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        xor_sum ^= bit[idx];
    }
    return xor_sum;
}

bool is_palindrome_possible(int mask) {
    return __builtin_popcount(mask) <= 1;
}

int main() {
    fast_io();

    std::cin >> N >> Q;
    std::cin >> S;

    bit.resize(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        update(i + 1, get_mask(S[i]));
    }

    for (int q = 0; q < Q; ++q) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int L;
            char x;
            std::cin >> L >> x;
            
            int old_mask = get_mask(S[L - 1]);
            int new_mask = get_mask(x);
            
            update(L, old_mask ^ new_mask);

            S[L - 1] = x;

        } else {
            int L, R;
            std::cin >> L >> R;

            int range_mask = query(R) ^ query(L - 1);
            
            if (is_palindrome_possible(range_mask)) {
                std::cout << "yes\n";
            } else {
                std::cout << "no\n";
            }
        }
    }

    return 0;
}
