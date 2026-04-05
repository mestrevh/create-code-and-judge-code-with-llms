/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

long long inc(long long n) {
    long long m = n;
    while (m >= 10) m /= 10;
    int firstDigit = static_cast<int>(m);
    return n + (firstDigit % 2 ? 1 : 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    while (!s.empty() && s[0] == '0') s.erase(s.begin());
    if (s.empty()) s = "0";

    long long n = 0;
    for (char c : s) n = n * 10 + (c - '0');

    cout << inc(n);
    return 0;
}