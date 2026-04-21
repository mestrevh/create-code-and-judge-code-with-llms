/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

/**
 * Problem: Cifra Maluca
 * Logic: Replace each consonant with the vowel immediately preceding it in the Latin alphabet.
 * Vowels: A, E, I, O, U
 * Mapping:
 * [B, C, D] -> A
 * [F, G, H] -> E
 * [J, K, L, M, N] -> I
 * [P, Q, R, S, T] -> O
 * [V, W, X, Y, Z] -> U
 * Everything else (vowels, spaces, special chars) remains unchanged but converted to uppercase.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    // Clear the input buffer to use getline properly
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (T--) {
        string line;
        if (!getline(cin, line)) break;

        string result = "";
        for (unsigned char c : line) {
            unsigned char up = c;

            // Convert lowercase to uppercase (handling basic Latin-1 range for characters like ç, é, etc.)
            if (up >= 'a' && up <= 'z') {
                up -= 32;
            } else if (up >= 224 && up <= 254 && up != 247) {
                up -= 32;
            }

            // Apply the mapping logic for consonants
            if (up >= 'B' && up <= 'D') {
                result += 'A';
            } else if (up >= 'F' && up <= 'H') {
                result += 'E';
            } else if (up >= 'J' && up <= 'N') {
                result += 'I';
            } else if (up >= 'P' && up <= 'T') {
                result += 'O';
            } else if (up >= 'V' && up <= 'Z') {
                result += 'U';
            } else {
                // Keep vowels and non-alphabetic characters as they are (now capitalized)
                result += (char)up;
            }
        }
        cout << result << "\n";
    }

    return 0;
}

