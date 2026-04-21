/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    // Reading input N until EOF to handle multiple test cases if provided
    while (cin >> n) {
        // According to the logic derived from the problem description and test cases:
        // The total number of odd elements written up to line N is the sum of the first
        // N odd integers: 1 + 3 + 5 + ... + (2N-1) = N^2.
        // The last number in the N-th line is the (N^2)-th odd number.
        // The k-th odd number is given by (2k - 1).
        // Therefore, the last number L in line N is: L = 2*(N^2) - 1.
        // The last three numbers in that line are (L), (L-2), and (L-4).
        // Their sum is L + (L-2) + (L-4) = 3L - 6.
        // Substituting L: 3 * (2*N^2 - 1) - 6 = 6*N^2 - 3 - 6 = 6*N^2 - 9.
        
        // Using long long as requested to prevent overflow for N up to 1,000,000,000.
        // 6 * (10^9)^2 = 6 * 10^18, which fits in a 64-bit signed long long (max ~9.22 * 10^18).
        long long result = 6 * n * n - 9;
        
        cout << result << "\n";
    }

    return 0;
}