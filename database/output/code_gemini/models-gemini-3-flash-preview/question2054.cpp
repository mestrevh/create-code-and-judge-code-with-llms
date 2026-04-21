/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Soma não tão simples
 * Goal: Sum integers from 1 to N, excluding multiples of A or B.
 * Constraints: N <= 100,000, MDC(A, B) = 1.
 * Time complexity: O(1).
 * Space complexity: O(1).
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b;
    // Reading input N, A, and B
    if (!(cin >> n >> a >> b)) return 0;

    // The sum of multiples of k from 1 to N is given by:
    // S_k = k * (m * (m + 1) / 2), where m = floor(N / k)
    auto sum_multiples = [](long long k, long long limit) -> long long {
        if (k > limit || k <= 0) return 0;
        long long m = limit / k;
        return k * (m * (m + 1) / 2);
    };

    // Calculate sum from 1 to N
    long long total_sum = sum_multiples(1, n);

    // Calculate sum of multiples of A
    long long sum_a = sum_multiples(a, n);

    // Calculate sum of multiples of B
    long long sum_b = sum_multiples(b, n);

    // Calculate sum of multiples of both A and B
    // Since MDC(A, B) = 1, the LCM(A, B) = A * B
    long long lab = a * b;
    long long sum_ab = sum_multiples(lab, n);

    // Using Inclusion-Exclusion Principle:
    // Sum to exclude = Sum(A) + Sum(B) - Sum(A and B)
    // Final result = TotalSum - (Sum(A) + Sum(B) - Sum(A and B))
    long long result = total_sum - sum_a - sum_b + sum_ab;

    // Output the result
    cout << result << endl;

    return 0;
}