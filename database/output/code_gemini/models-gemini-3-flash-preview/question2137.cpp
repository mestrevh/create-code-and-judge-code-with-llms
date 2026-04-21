/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem: Mersenne Sequence (Marsenne).
 * Rule: n belongs to the sequence if n is prime AND 2^n - 1 is prime.
 * Observations from test cases:
 * 1. The value 1 is included as the first element of the sequence.
 * 2. The output consists of the exponents 'n' that satisfy the rule.
 * 3. The threshold 'm' is exclusive (n < m).
 * 4. Trailing spaces are present in the output of each test case.
 */

int main() {
    // Optimize standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Known Mersenne prime exponents (n such that 2^n - 1 is prime).
    // These are known as Mersenne exponents. All Mersenne exponents > 1 are prime.
    // The list covers values of n up to the current known limits for competitive programming.
    int m_exp[] = {2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 
                   2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 
                   23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433};
    int total_exp = sizeof(m_exp) / sizeof(m_exp[0]);

    long long m;
    // Process multiple test cases until a negative value is provided.
    while (cin >> m && m >= 0) {
        // Based on test cases, the sequence starts at n=1 if m > 1.
        if (m > 1) {
            cout << "1 ";
            for (int i = 0; i < total_exp; ++i) {
                // Threshold is exclusive (n < m).
                if (m_exp[i] < m) {
                    cout << m_exp[i] << " ";
                } else {
                    // Since exponents are sorted, we can stop early.
                    break;
                }
            }
        }
        // Every line ends with a newline, even if empty (m <= 1).
        cout << "\n";
    }

    return 0;
}