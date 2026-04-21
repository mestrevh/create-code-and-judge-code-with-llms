/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static inline string trimSpaces(const string& s) {
    size_t l = 0, r = s.size();
    while (l < r && isspace((unsigned char)s[l])) l++;
    while (r > l && isspace((unsigned char)s[r - 1])) r--;
    return s.substr(l, r - l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;
    string s = trimSpaces(line);

    bool ok = true;

    if (s.size() < 10) ok = false;

    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (unsigned char c : s) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else ok = false;
    }

    if (!hasUpper || !hasLower || !hasDigit) ok = false;

    auto startsWith = [&](const string& pat) -> bool {
        return s.size() >= pat.size() && s.compare(0, pat.size(), pat) == 0;
    };
    auto endsWith = [&](const string& pat) -> bool {
        return s.size() >= pat.size() && s.compare(s.size() - pat.size(), pat.size(), pat) == 0;
    };

    if (startsWith("123") || endsWith("123")) ok = false;
    if (startsWith("321") || endsWith("321")) ok = false;
    if (startsWith("000") || endsWith("000")) ok = false;
    if (startsWith("abc") || endsWith("abc")) ok = false;

    cout << (ok ? "sucesso" : "fracasso") << "\n";
    return 0;
}