/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Calculates the sum of all divisors of n, including 1 and n.
 * Time complexity: O(sqrt(n))
 */
long long calculate_sum_divisors(long long n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    long long sum = 0;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long best_num = 0;
    long long max_divisor_sum = -1;

    // The problem specifies exactly 5 numbers
    for (int i = 0; i < 5; ++i) {
        long long current_val;
        if (!(cin >> current_val)) break;

        long long current_sum = calculate_sum_divisors(current_val);

        // Update the best number if the current one has a strictly larger sum of divisors.
        // In case of a tie, the first number encountered is usually preserved.
        if (current_sum > max_divisor_sum) {
            max_divisor_sum = current_sum;
            best_num = current_val;
        }
    }

    cout << best_num << "\n";

    return 0;
}