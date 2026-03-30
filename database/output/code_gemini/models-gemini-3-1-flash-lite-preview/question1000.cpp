/*
Código criado pelo models/gemini-3.1-flash-lite-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
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

    string reversed_vowels = vowels;
    reverse(reversed_vowels.begin(), reversed_vowels.end());

    if (vowels == reversed_vowels) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}