/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Checks if a character is one of the standard Portuguese/English vowels.
 */
bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c1, c2, c3;
    // Read the three characters from input
    if (!(cin >> c1 >> c2 >> c3)) return 0;

    // Validation: All characters must be uppercase letters ('A'-'Z')
    if (c1 < 'A' || c1 > 'Z' || c2 < 'A' || c2 > 'Z' || c3 < 'A' || c3 > 'Z') {
        cout << "Etiquetas erradas!" << endl;
        return 0;
    }

    // Sort characters to handle any order of input
    vector<char> v = {c1, c2, c3};
    sort(v.begin(), v.end());

    // Calculate distances between consecutive letters in the sorted sequence
    int d1 = v[1] - v[0];
    int d2 = v[2] - v[1];

    // Determine if any of the characters are vowels
    bool hasVowel = isVowel(v[0]) || isVowel(v[1]) || isVowel(v[2]);

    // Logic for identifying the type of sequence based on uniform distances
    if (d1 == 1 && d2 == 1) {
        // Distance of 1: Sequence
        if (hasVowel) cout << "Sequência quase perfeita." << endl;
        else cout << "Sequência perfeita." << endl;
    } else if (d1 == 2 && d2 == 2) {
        // Distance of 2: Bissequence
        if (hasVowel) cout << "Bissequência quase perfeita." << endl;
        else cout << "Bissequência perfeita." << endl;
    } else if (d1 == 3 && d2 == 3) {
        // Distance of 3: Trissequence
        if (hasVowel) cout << "Trissequência quase perfeita." << endl;
        else cout << "Trissequência perfeita." << endl;
    } else {
        // Distances are varied or not in the range {1, 2, 3}
        cout << "Só umas letras ai..." << endl;
    }

    return 0;
}