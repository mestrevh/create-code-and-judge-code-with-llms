/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    while (getline(cin, line)) {
        if (!s.empty()) s.push_back('\n');
        s += line;
    }

    long long count = 0;
    bool inWord = false;

    auto isEnglishLetter = [&](char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    };

    for (unsigned char uc : s) {
        char c = (char)uc;
        if (isEnglishLetter(c)) {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    cout << count << "\n";
    return 0;
}