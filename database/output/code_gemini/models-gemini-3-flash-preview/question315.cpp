/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Checks if a character is a valid hexadecimal digit.
 */
bool isHex(char c) {
    return (c >= '0' && c <= '9') || 
           (c >= 'a' && c <= 'f') || 
           (c >= 'A' && c <= 'F');
}

/**
 * Returns the decimal value of a single hexadecimal character.
 */
int hexVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0;
}

/**
 * Converts a hexadecimal string to its decimal equivalent.
 * Truncates processing if the value exceeds standard RGB limits
 * based on the context of the problem (up to 2 characters).
 */
int hexToDec(string s) {
    int res = 0;
    for (char c : s) {
        res = res * 16 + hexVal(c);
    }
    return res;
}

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    // Rule 1: Replace all non-hexadecimal characters with '0'
    string processed = "";
    for (char c : s) {
        if (isHex(c)) {
            processed += c;
        } else {
            processed += '0';
        }
    }

    // Rule 2: Advance to the next total number of characters divisible by 3.
    // Fill missing digits with 0s.
    if (processed.empty()) {
        processed = "000";
    } else {
        while (processed.length() % 3 != 0) {
            processed += '0';
        }
    }

    // Rule 3: Divide into three equal groups (R, G, B components).
    int k = processed.length() / 3;
    string r_s = processed.substr(0, k);
    string g_s = processed.substr(k, k);
    string b_s = processed.substr(2 * k, k);

    // Rule 4: Truncate each component from the right until it has at most 2 characters.
    if (r_s.length() > 2) r_s = r_s.substr(0, 2);
    if (g_s.length() > 2) g_s = g_s.substr(0, 2);
    if (b_s.length() > 2) b_s = b_s.substr(0, 2);

    // Convert truncated hex strings to decimal and output in (R,G,B) format.
    cout << "(" << hexToDec(r_s) << "," << hexToDec(g_s) << "," << hexToDec(b_s) << ")" << endl;

    return 0;
}