/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

// Using __int128 to handle potentially very large numbers for clock cycles
typedef unsigned __int128 uint128;

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R;
    if (!(cin >> R)) return 0;

    vector<string> results;
    for (int i = 0; i < R; ++i) {
        string S, F_str;
        if (!(cin >> S >> F_str)) break;

        int n = S.length();
        unsigned long long current_val = 0;
        
        // Convert the string to a binary representation (LSB at index 0)
        // 'X' represents state 0, 'O' represents state 1
        for (int j = 0; j < n; ++j) {
            if (S[j] == 'O') {
                current_val |= (1ULL << j);
            }
        }

        // Apply masking for N bits
        unsigned long long mask = (n == 64) ? ~0ULL : ((1ULL << n) - 1);
        
        // Parse the clock cycles F from string, keeping it within 2^n modulo
        uint128 f_val_parsed = 0;
        for (char c : F_str) {
            f_val_parsed = (f_val_parsed * 10 + (c - '0'));
            f_val_parsed &= (uint128)mask; 
        }
        
        unsigned long long f_val = (unsigned long long)f_val_parsed;
        
        // The ripple counter logic is identical to adding F to the binary value
        unsigned long long final_val = (current_val + f_val) & mask;

        // Convert the resulting value back into the string format
        string res = "";
        for (int j = 0; j < n; ++j) {
            if (final_val & (1ULL << j)) {
                res += 'O';
            } else {
                res += 'X';
            }
        }
        results.push_back(res);
        cout << res << "\n";
    }

    // Construct the "giant" light by joining all fios with ornaments
    if (results.empty()) return 0;

    string giant = results[0];
    for (size_t i = 1; i < results.size(); ++i) {
        char last_led = giant.back();
        char first_led_next = results[i][0];
        size_t current_total_len = giant.length();
        
        // Ornament logic based on size parity and state similarity
        if (current_total_len % 2 == 0) { // Size is even
            if (last_led == first_led_next) {
                giant += '@';
            } else {
                giant += '$';
            }
        } else { // Size is odd
            if (last_led == first_led_next) {
                giant += '#';
            } else {
                giant += '%';
            }
        }
        giant += results[i];
    }
    
    // Output the final joined string
    cout << giant << "\n";

    return 0;
}