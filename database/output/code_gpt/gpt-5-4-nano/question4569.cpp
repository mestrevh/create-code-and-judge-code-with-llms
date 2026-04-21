/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    int n = (int)s.size();
    bool ok = true;

    if (n < 3 || n > 30) ok = false;
    if (n == 0) ok = false;

    if (ok) {
        if (!isLetter(s.front()) || !isLetter(s.back())) ok = false;
    }

    if (ok) {
        for (char c : s) {
            if (!(isLetter(c) || c == ' ' || c == '-')) ok = false;
        }
    }

    if (ok) {
        for (int i = 1; i < n; i++) {
            if (s[i] == ' ' && s[i-1] == ' ') ok = false;
            if (s[i] == '-' && s[i-1] == '-') ok = false;
        }
    }

    if (ok) {
        for (int i = 0; i < n; i++) {
            if (isLetter(s[i])) {
                bool newWordStart = false;
                if (i == 0) newWordStart = true;
                else if (s[i-1] == ' ' || s[i-1] == '-') newWordStart = true;

                if (newWordStart) {
                    if (!(s[i] >= 'A' && s[i] <= 'Z')) ok = false;
                }
            }
        }
    }

    cout << s << ": " << (ok ? 1 : 0) << "\n";
    return 0;
}