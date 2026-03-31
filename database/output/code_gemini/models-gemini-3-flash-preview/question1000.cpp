/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    string vowels = "";
    for (char c : s) {
        if (is_vowel(c)) {
            vowels += c;
        }
    }

    bool is_palindrome = true;
    int n = vowels.length();
    for (int i = 0; i < n / 2; ++i) {
        if (vowels[i] != vowels[n - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}