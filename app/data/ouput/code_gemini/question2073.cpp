/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<long long> primes;
long long r_val;
std::vector<long long> generated_nums;

void generate(long long current_num, int prime_idx) {
    if (current_num > 1) {
        generated_nums.push_back(current_num);
    }

    for (int i = prime_idx; i < primes.size(); ++i) {
        if (current_num > r_val / primes[i]) {
            continue;
        }
        generate(current_num * primes[i], i);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long p1, p2, p3, l_val;
    std::cin >> p1 >> p2 >> p3 >> l_val >> r_val;

    primes.push_back(p1);
    primes.push_back(p2);
    primes.push_back(p3);

    std::sort(primes.begin(), primes.end());
    primes.erase(std::unique(primes.begin(), primes.end()), primes.end());

    generate(1, 0);

    std::vector<long long> results_in_range;
    for (long long num : generated_nums) {
        if (num >= l_val) {
            results_in_range.push_back(num);
        }
    }
    
    if (results_in_range.empty()) {
        std::cout << "0 0 0\n";
    } else {
        long long count = results_in_range.size();
        long long min_val = *std::min_element(results_in_range.begin(), results_in_range.end());
        long long max_val = *std::max_element(results_in_range.begin(), results_in_range.end());
        std::cout << count << " " << min_val << " " << max_val << "\n";
    }

    return 0;
}
