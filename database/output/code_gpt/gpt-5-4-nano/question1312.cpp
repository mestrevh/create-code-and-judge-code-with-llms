/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D;
    string P;
    int M;
    if (!(cin >> D >> P >> M)) return 0;

    string q = P;
    long long m = M;

    auto strip = [](string &s) {
        int i = 0;
        while (i + 1 < (int)s.size() && s[i] == '0') i++;
        if (i > 0) s.erase(0, i);
    };

    long long rem = 0;
    string quotient;
    quotient.reserve(q.size());

    for (char c : q) {
        int digit = c - '0';
        __int128 cur = (__int128)rem * m + digit;
        long long qd = (long long)(cur / m);
        rem = (long long)(cur % m);
        quotient.push_back(char('0' + qd));
    }

    strip(quotient);

    long long monitor = 0;
    if (quotient.size() == 0) monitor = 0;
    else {
        __int128 val = 0;
        for (char c : quotient) val = val * 10 + (c - '0');
        monitor = (long long)val / m;
    }

    cout << monitor << ' ' << rem << "\n";
    return 0;
}