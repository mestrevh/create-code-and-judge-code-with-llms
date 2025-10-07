/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_vowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    int n;
    cin >> n;
    vector<string> substrings;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = sqrt(s.length());
        int start = -1;
        for (int j = 0; j < s.length(); j++) {
            if (is_vowel(s[j])) {
                start = j;
                break;
            }
        }
        if (start != -1) {
            substrings.push_back(s.substr(start, x));
        }
    }
    sort(substrings.begin(), substrings.end());
    for (const string& sub : substrings) {
        cout << sub;
    }
    cout << endl;
    return 0;
}
