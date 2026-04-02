/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * The number of friends doubles every minute.
 * Minute 0: 1 friend (Ana).
 * Minute 1: 2 friends.
 * Minute 2: 4 friends.
 * ...
 * Minute N: 2^N friends.
 * 
 * Input: N (up to 10^5).
 * Output: 2^N with 50 digits per line.
 * 
 * Strategy:
 * Use a BigInt implementation in base 10^9.
 * For efficiency, multiply by 2^30 repeatedly to calculate 2^N.
 * Total operations: O(N^2 / base_multiplier), which easily passes in 5s.
 */

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Corner case for N = 0
    if (n == 0) {
        cout << "1" << endl;
        return 0;
    }

    // BigInt storage in base 10^9
    vector<unsigned long long> res;
    res.push_back(1);
    const unsigned long long base = 1000000000ULL;

    // Helper to multiply BigInt by a factor
    auto multiply = [&](unsigned long long mult) {
        unsigned long long carry = 0;
        for (size_t j = 0; j < res.size(); ++j) {
            unsigned long long val = res[j] * mult + carry;
            res[j] = val % base;
            carry = val / base;
        }
        while (carry) {
            res.push_back(carry % base);
            carry /= base;
        }
    };

    // Calculate 2^n in steps of 2^30 to speed up calculation
    int full_steps = n / 30;
    int rem_steps = n % 30;

    for (int i = 0; i < full_steps; ++i) {
        multiply(1ULL << 30);
    }
    if (rem_steps > 0) {
        multiply(1ULL << rem_steps);
    }

    // Convert base 10^9 chunks back to a single decimal string
    string result_str = to_string(res.back());
    for (int i = (int)res.size() - 2; i >= 0; --i) {
        string chunk = to_string(res[i]);
        // Each chunk except the most significant must be 9 digits
        result_str.append(9 - chunk.size(), '0');
        result_str += chunk;
    }

    // Output formatting: max 50 digits per line
    for (int i = 0; i < (int)result_str.size(); ++i) {
        cout << result_str[i];
        if ((i + 1) % 50 == 0) {
            cout << "\n";
        }
    }
    // Final newline if the last line wasn't exactly 50 chars
    if (result_str.size() % 50 != 0) {
        cout << "\n";
    }

    return 0;
}