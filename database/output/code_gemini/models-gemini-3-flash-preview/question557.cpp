/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Optimal Matrix Chain Multiplication Parenthesization
 * Complexity: O(N^3) time and O(N^2) space, where N <= 10.
 */

long long dp[15][15];
int split[15][15];
long long r[15], c[15];

// Recursive function to print the optimal parenthesization using stored splits.
void print_optimal(int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    print_optimal(i, split[i][j]);
    cout << " x ";
    print_optimal(split[i][j] + 1, j);
    cout << ")";
}

int main() {
    // Optimize standard C++ I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int caseNum = 1;
    
    // Process test cases until n equals 0.
    while (cin >> n && n != 0) {
        for (int i = 1; i <= n; ++i) {
            cin >> r[i] >> c[i];
        }

        // Initialize Dynamic Programming table.
        // dp[i][j] will store the minimum cost to multiply matrices from index i to j.
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = -1; // -1 represents infinity/uncalculated state.
            }
            dp[i][i] = 0; // Multiplication of a single matrix has zero cost.
        }

        // len is the length of the chain of matrices being considered.
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n - len + 1; ++i) {
                int j = i + len - 1;
                for (int k = i; k < j; ++k) {
                    /*
                     * Standard Matrix Multiplication Cost Rule:
                     * Cost(A*B) = rows(A) * cols(B) * cols(A).
                     * Here A is the product of matrices from i to k, 
                     * and B is the product of matrices from k+1 to j.
                     * rows(A) = r[i]
                     * cols(B) = c[j]
                     * cols(A) = c[k]
                     */
                    long long cost = dp[i][k] + dp[k + 1][j] + r[i] * c[j] * c[k];
                    
                    // Update minimum cost and store the split point for reconstruction.
                    if (dp[i][j] == -1 || cost < dp[i][j]) {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }

        // Output results in the specified format.
        cout << "Case " << caseNum++ << ": ";
        if (n == 1) {
            // Special case for a single matrix.
            cout << "(A1)" << endl;
        } else {
            print_optimal(1, n);
            cout << endl;
        }
    }

    return 0;
}