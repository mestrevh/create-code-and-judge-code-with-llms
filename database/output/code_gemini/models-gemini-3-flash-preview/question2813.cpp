/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Competitive Programming Solution
 * Problem: PR1_Media_Loop
 * Complexity: O(1) time, O(1) space
 */

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Prompt as specified in the problem description and test cases
    cout << "Digite um numero positivo:" << endl;

    long long n;
    // Read input value
    if (cin >> n) {
        // Validation: Only allow non-negative integers
        if (n < 0) {
            cout << "Apenas valores positivos" << endl;
        } else {
            /**
             * The sum of an arithmetic progression from 1 to n is:
             * S = n * (1 + n) / 2
             * The average is S / n:
             * Average = (n * (1 + n) / 2) / n = (n + 1) / 2
             * We use double for floating point result as per test cases (e.g., 5.5).
             */
            double media = (static_cast<double>(n) + 1.0) / 2.0;
            
            // Output format following the test case: "Media de 1 ate [n]: [result]"
            cout << "Media de 1 ate " << n << ": " << media << endl;
        }
    }

    return 0;
}