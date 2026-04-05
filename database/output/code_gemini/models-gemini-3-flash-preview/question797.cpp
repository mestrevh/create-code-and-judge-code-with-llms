/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * Problem: Fortaleza Digital
 * Logic:
 * 1. Read the number of test cases T.
 * 2. For each test case, read the entire line as a ciphered text.
 * 3. If the length C of the string is not a perfect square, output "INVALIDO".
 * 4. Otherwise, calculate N = sqrt(C).
 * 5. The cipher was filled into an N x N matrix row by row.
 * 6. To decipher, read the matrix column by column.
 * 7. Deciphered text D[k] = S[(k % N) * N + (k / N)].
 */

int main() {
    // Optimize I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read number of test cases
    if (!(cin >> T)) return 0;

    string line;
    // Consume the leftover newline character from the T input
    getline(cin, line);

    while (T--) {
        // Read the ciphered line
        if (!getline(cin, line)) break;

        // Strip carriage return characters that might exist in Windows-formatted files
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        long long C = line.length();
        
        // Handle potentially empty strings
        if (C == 0) {
            cout << "\n";
            continue;
        }

        // Find if C is a perfect square using binary search to avoid floating point precision issues
        long long N = -1;
        long long low = 1, high = 1000000; // sqrt(10^12)
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;
            if (sq == C) {
                N = mid;
                break;
            } else if (sq < C) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Check if C is a perfect square
        if (N == -1) {
            cout << "INVALIDO\n";
        } else {
            // Build the decoded string by reading the virtual N x N matrix column by column
            string decoded = "";
            decoded.resize(C);
            int idx = 0;
            for (long long j = 0; j < N; ++j) {       // Iterate through columns
                for (long long i = 0; i < N; ++i) {   // Iterate through rows
                    decoded[idx++] = line[i * N + j];
                }
            }
            // Output the deciphered text
            cout << decoded << "\n";
        }
    }

    return 0;
}