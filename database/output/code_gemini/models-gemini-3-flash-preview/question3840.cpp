/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VAL = 100005;
int odd_count_factors[MAX_VAL];
bool has_repeating_odd_factor[MAX_VAL];
bool is_prime_num[MAX_VAL];

void precompute_sieve() {
    for (int i = 0; i < MAX_VAL; ++i) {
        is_prime_num[i] = true;
        odd_count_factors[i] = 0;
        has_repeating_odd_factor[i] = false;
    }
    is_prime_num[0] = is_prime_num[1] = false;
    for (int p = 2; p < MAX_VAL; ++p) {
        if (is_prime_num[p]) {
            if (p % 2 != 0) {
                // Factor is odd prime
                for (int j = p; j < MAX_VAL; j += p) {
                    odd_count_factors[j]++;
                }
                // Check for repetitions of this odd prime factor
                long long p_sq = (long long)p * p;
                if (p_sq < MAX_VAL) {
                    for (int j = (int)p_sq; j < MAX_VAL; j += (int)p_sq) {
                        has_repeating_odd_factor[j] = true;
                    }
                }
            }
            // Standard sieve to mark multiples of prime p
            for (long long j = (long long)p * p; j < MAX_VAL; j += p) {
                is_prime_num[j] = false;
            }
        }
    }
}

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_sieve();

    int N, K, P;
    if (!(cin >> N >> K >> P)) {
        return 0;
    }

    vector<int> results;
    // The range is [N, K-1]
    for (int i = N; i < K; ++i) {
        // Prime factorization is typically considered for integers >= 1
        if (i >= 1 && i < MAX_VAL) {
            if (odd_count_factors[i] == P && !has_repeating_odd_factor[i]) {
                results.push_back(i);
            }
        }
    }

    if (results.empty()) {
        cout << "Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo." << endl;
    } else {
        // Output format: first valid number followed by the count of subsequent valid numbers
        cout << results[0] << " " << (int)results.size() - 1 << endl;
    }

    return 0;
}