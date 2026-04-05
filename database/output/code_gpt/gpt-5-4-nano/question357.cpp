/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long cents;
    if (!(cin >> ws)) return 0;

    string s;
    cin.clear();
    cin.seekg(0, ios::beg);
    if (!(cin >> s)) return 0;

    bool neg = false;
    if (!s.empty() && s[0] == '-') { neg = true; s = s.substr(1); }

    size_t pos = s.find('.');
    long long realPart = 0, fracPart = 0;
    if (pos == string::npos) {
        realPart = stoll(s.empty() ? "0" : s);
    } else {
        string a = s.substr(0, pos);
        string b = s.substr(pos + 1);
        if (a.empty()) realPart = 0;
        else realPart = stoll(a);
        if (b.size() == 0) fracPart = 0;
        else if (b.size() == 1) fracPart = (b[0]-'0') * 10;
        else fracPart = (b[0]-'0') * 10 + (b[1]-'0');
    }
    cents = realPart * 100 + fracPart;
    if (neg) cents = -cents;

    long long prestaCents = cents / 3;
    long long entradaCents = cents - 2 * prestaCents;

    auto printMoney = [&](long long x) {
        if (x < 0) { cout << "-"; x = -x; }
        cout << (x / 100) << ".";
        long long frac = x % 100;
        cout << setw(2) << setfill('0') << frac << setfill(' ') << "\n";
    };

    printMoney(entradaCents);
    printMoney(prestaCents);
    printMoney(prestaCents);

    return 0;
}