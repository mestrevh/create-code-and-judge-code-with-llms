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

    int n;
    std::cin >> n;

    if (n <= 0) {
        long long i_val, x_val;
        if (n == 0) {
             std::cin >> i_val >> x_val;
        }
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<long long> arr(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        total_sum += arr[i];
    }

    long long i;
    long long x;
    std::cin >> i >> x;

    long long final_sum = 0;
    
    long long full_loops = x / n;
    final_sum += full_loops * total_sum;

    long long remaining_elements = x % n;
    long long start_index = i % n;

    for (long long k = 0; k < remaining_elements; ++k) {
        final_sum += arr[(start_index + k) % n];
    }

    std::cout << final_sum << std::endl;

    return 0;
}
