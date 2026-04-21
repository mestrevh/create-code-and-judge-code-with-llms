/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimize input and output speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    // Read the two input strings, allowing for spaces
    if (!getline(cin, s1)) return 0;
    if (!getline(cin, s2)) return 0;

    // Use an array to store the frequency of letters 'a' through 'z'
    int counts[26] = {0};

    // Count occurrences in the first string, ignoring case and non-letter characters
    for (char c : s1) {
        if (c >= 'a' && c <= 'z') {
            counts[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        }
    }

    // Subtract occurrences in the second string
    for (char c : s2) {
        if (c >= 'a' && c <= 'z') {
            counts[c - 'a']--;
        } else if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']--;
        }
    }

    // If all letter counts are zero, the strings are anagrams
    bool is_anagram = true;
    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) {
            is_anagram = false;
            break;
        }
    }

    // Output the result as a boolean string
    if (is_anagram) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}