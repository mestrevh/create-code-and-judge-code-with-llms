/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> tokens;
    string s;
    while (cin >> s) tokens.push_back(s);

    auto parseToCents = [&](const string& str, bool &ok) -> long long {
        ok = false;
        string t;
        for (char c : str) if (!isspace((unsigned char)c)) t.push_back(c);
        if (t.empty()) return 0;
        bool neg = false;
        size_t i = 0;
        if (t[0] == '+' || t[0] == '-') {
            neg = (t[0] == '-');
            i = 1;
        }
        if (i >= t.size()) return 0;

        long long intPart = 0;
        bool hasDigit = false;
        for (; i < t.size() && isdigit((unsigned char)t[i]); i++) {
            hasDigit = true;
            intPart = intPart * 10 + (t[i] - '0');
        }
        if (!hasDigit) return 0;

        long long fracPart = 0;
        int fracDigits = 0;

        if (i < t.size()) {
            if (t[i] != '.') return 0;
            i++;
            size_t start = i;
            while (i < t.size() && isdigit((unsigned char)t[i])) {
                if (fracDigits < 2) {
                    fracPart = fracPart * 10 + (t[i] - '0');
                    fracDigits++;
                }
                i++;
            }
            if (i < t.size()) return 0;
            if (fracDigits == 0) return 0;
            if (fracDigits == 1) fracPart *= 10;
        } else {
            fracDigits = 0;
        }

        long long cents = intPart * 100 + (fracDigits ? fracPart : 0);
        if (neg) cents = -cents;
        ok = true;
        return cents;
    };

    auto solve = [&](long long cents) {
        long long maxCents = 620;
        long long minCents = 70;
        if (cents < minCents || cents > maxCents) return false;
        if (cents % 10 != 0) return false;

        long long X = cents / 50;
        while (X >= 0) {
            long long rem = cents - 50 * X;
            if (rem % 20 == 0) {
                long long Y = rem / 20;
                cout << "Compre " << X << " selo(s) de R$ 0.50 e " << Y << " selo(s) de R$ 0.20!\n";
                return true;
            }
            X--;
        }
        return false;
    };

    bool firstValidProcessed = false;
    for (size_t idx = 0; idx < tokens.size(); idx++) {
        bool ok = false;
        long long cents = parseToCents(tokens[idx], ok);
        if (!ok || !solve(cents)) {
            cout << "Preco invalido, refaça a leitura do pacote.\n";
        }
        if (ok) firstValidProcessed = true;
    }

    return 0;
}