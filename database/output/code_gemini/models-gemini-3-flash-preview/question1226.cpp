/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem: Find the largest even element in a list of integers.
 * Complexity: O(N) time, O(1) additional space (excluding input buffer).
 */

long long get_max_even_from_input() {
    long long max_even = LLONG_MIN;
    bool found = false;
    string current = "";
    char c;

    // Fast I/O is handled in main. 
    // We read char by char to handle brackets, commas, and other non-numeric delimiters.
    while (cin.get(c)) {
        if ((c >= '0' && c <= '9') || c == '-') {
            current += c;
        } else {
            if (!current.empty() && current != "-") {
                long long val = stoll(current);
                if (val % 2 == 0) {
                    if (!found || val > max_even) {
                        max_even = val;
                        found = true;
                    }
                }
            }
            current.clear();
        }
    }

    // Process the last token if it exists
    if (!current.empty() && current != "-") {
        long long val = stoll(current);
        if (val % 2 == 0) {
            if (!found || val > max_even) {
                max_even = val;
                found = true;
            }
        }
    }

    return found ? max_even : LLONG_MIN;
}

int main() {
    // Optimize standard I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long result = get_max_even_from_input();
    
    if (result != LLONG_MIN) {
        cout << result << endl;
    }

    return 0;
}