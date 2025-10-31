/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    std::vector<long long> A(T);
    for (int i = 0; i < T; ++i) {
        std::cin >> A[i];
    }
    long long X;
    std::cin >> X;

    if (T <= 0) {
        std::cout << "Esse numero deve estar errado..." << std::endl;
        return 0;
    }

    std::vector<long long> prefix(T);
    long long current_sum = 0;
    for (int i = 0; i < T; ++i) {
        current_sum += A[i];
        prefix[i] = current_sum;
    }
    long long total_sum_per_loop = current_sum;

    if (total_sum_per_loop == 0) {
        for (int p = 0; p < T; ++p) {
            if (prefix[p] == X) {
                std::cout << p << " " << 0 << std::endl;
                return 0;
            }
        }
        std::cout << "Esse numero deve estar errado..." << std::endl;
        return 0;
    }

    long long min_L = -1;
    int best_p = -1;

    for (int p = 0; p < T; ++p) {
        long long current_L = -1;
        if (total_sum_per_loop > 0) {
            long long diff = X - prefix[p];
            if (diff >= 0 && diff % total_sum_per_loop == 0) {
                current_L = diff / total_sum_per_loop;
            }
        } else {
            long long diff = prefix[p] - X;
            if (diff >= 0 && diff % (-total_sum_per_loop) == 0) {
                current_L = diff / (-total_sum_per_loop);
            }
        }
        
        if (current_L != -1) {
            if (min_L == -1 || current_L < min_L) {
                min_L = current_L;
                best_p = p;
            }
        }
    }

    if (best_p != -1) {
        std::cout << best_p << " " << min_L << std::endl;
    } else {
        std::cout << "Esse numero deve estar errado..." << std::endl;
    }

    return 0;
}
