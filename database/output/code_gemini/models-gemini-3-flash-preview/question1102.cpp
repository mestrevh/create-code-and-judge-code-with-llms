/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    if (!getline(cin, line)) {
        return 0;
    }

    stringstream ss(line);
    vector<string> words;
    string w;
    while (ss >> w) {
        words.push_back(w);
    }

    if (words.size() != 2) {
        cout << "ERRO" << endl;
        return 0;
    }

    string s1 = words[0];
    string s2 = words[1];

    if (s1.length() != s2.length()) {
        cout << "ERRO" << endl;
        return 0;
    }

    for (char c : s1) {
        if (c >= 'A' && c <= 'Z') {
            cout << "ERRO" << endl;
            return 0;
        }
    }
    for (char c : s2) {
        if (c >= 'A' && c <= 'Z') {
            cout << "ERRO" << endl;
            return 0;
        }
    }

    string result = "";
    for (int i = 0; i < (int)s1.length(); ++i) {
        bool equal = (s1[i] == s2[i]);
        bool is_vowel = (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u');

        if (equal && !is_vowel) {
            cout << i;
        } else if (i % 2 == 0) {
            cout << (char)toupper((unsigned char)s1[i]);
        } else {
            cout << "!!";
        }
    }
    cout << endl;

    return 0;
}