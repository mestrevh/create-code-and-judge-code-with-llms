/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static long long gcdll(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n')) s.pop_back();

    string aStr, bStr, cStr, dStr, plusStr, slashStr;

    auto parseFraction = [&](const string& x, long long &num, long long &den) -> bool {
        size_t p = x.find('/');
        if (p == string::npos) return false;
        string n = x.substr(0, p);
        string d = x.substr(p + 1);
        if (n.empty() || d.empty()) return false;
        try {
            num = stoll(n);
            den = stoll(d);
        } catch (...) {
            return false;
        }
        return true;
    };

    string t1, t2, t3;
    {
        stringstream ss(s);
        ss >> t1;
        ss >> plusStr;
        ss >> t3;
        if (t1.empty() || t3.empty()) {
            cout << "entrada invalida!";
            return 0;
        }
        long long a, b, c, d;
        if (!parseFraction(t1, a, b) || !parseFraction(t3, c, d)) {
            cout << "entrada invalida!";
            return 0;
        }
        if (b == 0 || d == 0) {
            cout << "entrada invalida!";
            return 0;
        }
        long long num = a * d + c * b;
        long long den = b * d;

        if (num == 0) {
            cout << "0/1\n";
            return 0;
        }

        long long g = gcdll(num, den);
        num /= g;
        den /= g;

        if (den < 0) {
            den = -den;
            num = -num;
        }

        cout << num << "/" << den << "\n";
    }

    return 0;
}