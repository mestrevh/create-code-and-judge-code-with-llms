/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int uint32;

uint32 next_state(uint32 s, int n, uint32 tap_mask) {
    uint32 b = __builtin_popcount(s & tap_mask) & 1;
    return (s >> 1) | (b << (n - 1));
}

struct Matrix {
    uint32 row[32];
    int n;
    Matrix(int _n) : n(_n) {
        for (int i = 0; i < 32; ++i) row[i] = 0;
    }
    static Matrix identity(int n) {
        Matrix res(n);
        for (int i = 0; i < n; ++i) res.row[i] = (1U << i);
        return res;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix res(n);
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if ((row[i] >> k) & 1)
                    res.row[i] ^= other.row[k];
            }
        }
        return res;
    }
};

uint32 apply(const Matrix& m, uint32 s) {
    uint32 res = 0;
    for (int i = 0; i < m.n; ++i) {
        if (__builtin_parity(m.row[i] & s))
            res |= (1U << i);
    }
    return res;
}

Matrix power(Matrix a, long long b) {
    Matrix res = Matrix::identity(a.n);
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    while (cin >> n >> t && (n || t)) {
        uint32 tap_mask = 0;
        for (int i = 0; i < t; ++i) {
            int tap;
            cin >> tap;
            tap_mask |= (1U << tap);
        }
        uint32 initial, final;
        cin >> hex >> initial >> final >> dec;

        if (initial == final) {
            cout << 0 << "\n";
            continue;
        }

        int m = 1 << (n / 2 + 1);
        if (m > (1 << 16)) m = 1 << 16;

        vector<pair<uint32, int>> baby_steps;
        baby_steps.reserve(m);
        uint32 curr = initial;
        bool found = false;
        for (int j = 0; j < m; ++j) {
            if (curr == final) {
                cout << dec << j << "\n";
                found = true;
                break;
            }
            baby_steps.push_back({curr, j});
            curr = next_state(curr, n, tap_mask);
            if (curr == initial) break;
        }
        if (found) continue;

        sort(baby_steps.begin(), baby_steps.end());

        Matrix M_inv(n);
        M_inv.row[0] = (1U << (n - 1));
        for (int i = 1; i < n; ++i) {
            if (tap_mask & (1U << i)) {
                M_inv.row[0] ^= (1U << (i - 1));
            }
            M_inv.row[i] = (1U << (i - 1));
        }

        Matrix M_inv_m = power(M_inv, m);
        curr = final;
        long long total_steps = -1;
        long long max_giant_steps = ((1LL << n) / m) + 2;
        for (int i = 1; i <= max_giant_steps; ++i) {
            curr = apply(M_inv_m, curr);
            auto it = lower_bound(baby_steps.begin(), baby_steps.end(), make_pair(curr, 0));
            if (it != baby_steps.end() && it->first == curr) {
                total_steps = (long long)i * m + it->second;
                break;
            }
            if (curr == final) break;
        }

        if (total_steps != -1) cout << dec << total_steps << "\n";
        else cout << "*\n";
    }
    return 0;
}