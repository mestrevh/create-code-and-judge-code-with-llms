/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static string trim(const string& s) {
    size_t a = 0;
    while (a < s.size() && isspace((unsigned char)s[a])) a++;
    size_t b = s.size();
    while (b > a && isspace((unsigned char)s[b-1])) b--;
    return s.substr(a, b-a);
}

struct Parser {
    string s;
    int n;
    long long x, y;

    Parser(string str, long long x_, long long y_) : s(std::move(str)), n((int)s.size()), x(x_), y(y_) {}

    void skipSpaces(int &i) {
        while (i < n && isspace((unsigned char)s[i])) i++;
    }

    long long parseSignedTerm(int &i) {
        skipSpaces(i);
        long long sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        skipSpaces(i);

        long long coef = parseNumber(i);
        skipSpaces(i);

        long long val = coef;
        bool hasMul = false;

        while (true) {
            skipSpaces(i);
            if (i >= n) break;
            if (s[i] == '*' && !hasMul) {
                hasMul = true;
                i++;
                continue;
            }
            if (s[i] == 'x' || s[i] == 'y') {
                long long baseVal;
                if (s[i] == 'x') baseVal = x;
                else baseVal = y;
                i++;
                skipSpaces(i);
                long long exp = 1;
                if (i < n && s[i] == '^') {
                    i++;
                    skipSpaces(i);
                    exp = parseNumber(i);
                }
                val *= powll(baseVal, exp);
                continue;
            }
            break;
        }

        return sign * val;
    }

    long long parseNumber(int &i) {
        skipSpaces(i);
        long long v = 0;
        bool any = false;
        while (i < n && isdigit((unsigned char)s[i])) {
            any = true;
            v = v * 10 + (s[i] - '0');
            i++;
        }
        if (!any) return 1;
        return v;
    }

    static long long powll(long long a, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = r * a;
            e >>= 1;
            if (e) a = a * a;
        }
        return r;
    }

    long long parseExpr() {
        int i = 0;
        long long sum = 0;
        skipSpaces(i);
        bool first = true;
        while (true) {
            skipSpaces(i);
            if (i >= n) break;
            long long term = parseSignedTerm(i);
            sum += term;
            skipSpaces(i);
            if (i >= n) break;
            if (s[i] == '+' || s[i] == '-') continue;
            if (s[i] == '*') { i++; continue; }
            break;
        }
        return sum;
    }
};

static bool parsePoint(const string& line, long long &x, long long &y) {
    string t;
    for (char c : line) t.push_back(c);
    int i = 0, n = (int)t.size();
    while (i < n && !isdigit((unsigned char)t[i])) i++;
    if (i >= n) return false;
    long long vx = 0;
    while (i < n && isdigit((unsigned char)t[i])) {
        vx = vx * 10 + (t[i] - '0');
        i++;
    }
    while (i < n && !isdigit((unsigned char)t[i])) i++;
    if (i >= n) return false;
    long long vy = 0;
    while (i < n && isdigit((unsigned char)t[i])) {
        vy = vy * 10 + (t[i] - '0');
        i++;
    }
    x = vx; y = vy;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line1, line2;
    if (!getline(cin, line1)) return 0;
    if (!getline(cin, line2)) return 0;

    long long x = 0, y = 0;
    if (!parsePoint(line1, x, y)) return 0;

    string denom = trim(line2);
    for (char &c : denom) {
        if (c == '−') c = '-';
    }

    Parser p(denom, x, y);
    long long denomVal = p.parseExpr();

    if (denomVal != 0) {
        cout << "a função está definida em (" << x << "," << y << ")\n";
    } else {
        cout << "a função não está definida em (" << x << "," << y << ") .-.\n";
    }
    return 0;
}