/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <utility>

using namespace std;

/**
 * Checks if the input string contains any digit characters.
 * @param s The input string.
 * @return True if a digit is found, false otherwise.
 */
bool contains_digit(const string& s) {
    for (char c : s) {
        if (isdigit((unsigned char)c)) return true;
    }
    return false;
}

/**
 * Performs Leet substitution and reverses the resulting string.
 * @param s The input string.
 * @return A pair containing the transformed string and the substitution count.
 */
pair<string, int> transform_and_reverse(const string& s) {
    string transformed = "";
    int count = 0;
    for (char c : s) {
        if (c == 'a' || c == 'A') {
            transformed += '@';
            count++;
        } else if (c == 'e' || c == 'E') {
            transformed += '3';
            count++;
        } else if (c == 'i' || c == 'I') {
            transformed += '1';
            count++;
        } else if (c == 'o' || c == 'O') {
            transformed += '0';
            count++;
        } else if (c == 't' || c == 'T') {
            transformed += '7';
            count++;
        } else if (c == 's' || c == 'S') {
            transformed += '5';
            count++;
        } else {
            transformed += c;
        }
    }
    reverse(transformed.begin(), transformed.end());
    return {transformed, count};
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    // Read the entire line from standard input
    if (!getline(cin, input) || input.empty()) {
        cout << "vazio" << "\n";
        cout << 0 << "\n";
        return 0;
    }

    // Rule: if the string contains at least one number, report error
    if (contains_digit(input)) {
        cout << "numeros" << "\n";
        cout << 0 << "\n";
        return 0;
    }

    // Process the string: substitution and reversal
    pair<string, int> result = transform_and_reverse(input);

    // Output the results
    cout << result.first << "\n";
    cout << result.second << "\n";

    return 0;
}