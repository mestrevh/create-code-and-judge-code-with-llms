/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    // Read the two large numbers as strings
    if (!(cin >> s1 >> s2)) return 0;

    // Handle the case where strings might be empty (safety)
    if (s1.empty() && s2.empty()) {
        cout << "0" << endl;
        return 0;
    }
    if (s1.empty()) { cout << s2 << endl; return 0; }
    if (s2.empty()) { cout << s1 << endl; return 0; }

    int i = (int)s1.size() - 1;
    int j = (int)s2.size() - 1;
    int carry = 0;

    string res;
    // Reserve memory to avoid multiple reallocations
    res.reserve(max(s1.size(), s2.size()) + 1);

    // Standard schoolbook addition algorithm
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += (s1[i] - '0');
            i--;
        }
        if (j >= 0) {
            sum += (s2[j] - '0');
            j--;
        }
        res.push_back((char)((sum % 10) + '0'));
        carry = sum / 10;
    }

    // Remove leading zeros that may have come from input (e.g., "001" + "002")
    // but ensure at least one digit remains if the result is 0
    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }

    // Since we added from right to left using push_back, reverse the result
    reverse(res.begin(), res.end());

    // Print the final sum
    if (res.empty()) cout << "0\n";
    else cout << res << "\n";

    return 0;
}