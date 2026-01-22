/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <climits>

long long power(long long base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; ++i) {
        if (base > 1 && res > LLONG_MAX / base) {
            return -1;
        }
        if (base == 0 && exp > 0) return 0;
        if (base == 1) return 1;
        res *= base;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long H, W;
    while (std::cin >> H >> W && (H != 0 || W != 0)) {
        long long n = 0;
        int K = 0;

        if (W == 1) {
            n = 1;
            if (H == 1) {
                K = 0;
            } else {
                K = static_cast<int>(round(log2(H)));
            }
        } else {
            for (int k_test = 1; k_test <= 62; ++k_test) {
                long long n_cand = static_cast<long long>(round(pow(W, 1.0 / k_test)));
                if (n_cand < 1) continue;
                
                if (power(n_cand, k_test) == W && power(n_cand + 1, k_test) == H) {
                    n = n_cand;
                    K = k_test;
                    break;
                }
            }
        }

        long long not_working_cats;
        if (n == 1) {
            not_working_cats = K;
        } else {
            not_working_cats = (W - 1) / (n - 1);
        }

        long long total_height = 0;
        long long h = 1;
        long long cats_at_level = W;
        for (int i = 0; i <= K; ++i) {
            total_height += cats_at_level * h;
            if (i < K) {
                if (n == 0) break; 
                cats_at_level /= n;
                h *= (n + 1);
            }
        }
        
        std::cout << not_working_cats << " " << total_height << "\n";
    }

    return 0;
}
