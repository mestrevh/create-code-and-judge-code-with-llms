/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

const double PI = acos(-1.0);
const int MAX_A = 100000;
const int MAX_K = 200000;

using cd = std::complex<double>;

void fft(std::vector<cd>& a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a)
            x /= n;
    }
}

std::vector<long long> multiply(const std::vector<int>& a) {
    std::vector<cd> fa(a.begin(), a.end());
    int n = 1;
    while (n < a.size() + a.size()) n <<= 1;
    fa.resize(n);

    fft(fa, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fa[i];
    fft(fa, true);

    std::vector<long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> num_freq(MAX_A + 1, 0);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        num_freq[val]++;
        max_val = std::max(max_val, val);
    }
    
    num_freq.resize(max_val + 1);

    std::vector<long long> conv_coeffs = multiply(num_freq);
    
    int max_sum = 2 * max_val;
    if (conv_coeffs.size() < max_sum + 1) {
        conv_coeffs.resize(max_sum + 1, 0);
    }

    std::vector<long long> pairs_for_sum(max_sum + 1, 0);

    for (int s = 0; s <= max_sum; ++s) {
        long long current_val = conv_coeffs[s];
        if (s % 2 == 0) {
            int val = s / 2;
            if (val < num_freq.size()) {
                current_val -= (long long)num_freq[val] * num_freq[val];
            }
        }
        pairs_for_sum[s] = current_val / 2;
    }

    for (int val = 1; val < num_freq.size(); ++val) {
        if (num_freq[val] >= 2) {
            pairs_for_sum[2 * val] += (long long)num_freq[val] * (num_freq[val] - 1) / 2;
        }
    }

    std::vector<long long> ans(MAX_K + 1, 0);
    for (int k = 1; k <= MAX_K; ++k) {
        for (int s = k; s <= max_sum; s += k) {
            ans[k] += pairs_for_sum[s];
        }
    }
    
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        std::cout << ans[k] << "\n";
    }

    return 0;
}
