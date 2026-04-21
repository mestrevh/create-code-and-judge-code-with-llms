/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    if (!getline(cin, a)) return 0;
    if (!getline(cin, b)) return 0;

    auto trim = [](string &s) {
        size_t i = 0;
        while (i < s.size() && isspace(static_cast<unsigned char>(s[i]))) i++;
        s.erase(0, i);
        while (!s.empty() && isspace(static_cast<unsigned char>(s.back()))) s.pop_back();
    };
    trim(a);
    trim(b);

    auto isNeg = [](const string& s) {
        return !s.empty() && s[0] == '-';
    };
    bool negA = isNeg(a), negB = isNeg(b);
    if (negA) a.erase(a.begin());
    if (negB) b.erase(b.begin());

    auto stripZeros = [](string &s) {
        size_t p = 0;
        while (p + 1 < s.size() && s[p] == '0') p++;
        if (p) s.erase(0, p);
        if (s.empty()) s = "0";
    };
    stripZeros(a);
    stripZeros(b);

    auto cmpAbs = [&](const string& x, const string& y) -> int {
        if (x.size() != y.size()) return x.size() < y.size() ? -1 : 1;
        if (x == y) return 0;
        return x < y ? -1 : 1;
    };

    auto addAbs = [&](const string& x, const string& y) -> string {
        int i = (int)x.size() - 1, j = (int)y.size() - 1, carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += x[i--] - '0';
            if (j >= 0) sum += y[j--] - '0';
            res.push_back(char('0' + (sum % 10)));
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        stripZeros(res);
        return res;
    };

    auto subAbs = [&](const string& x, const string& y) -> string {
        int i = (int)x.size() - 1, j = (int)y.size() - 1;
        int borrow = 0;
        string res;
        while (i >= 0) {
            int cur = (x[i] - '0') - borrow - (j >= 0 ? (y[j] - '0') : 0);
            if (cur < 0) cur += 10, borrow = 1;
            else borrow = 0;
            res.push_back(char('0' + cur));
            i--; j--;
        }
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        stripZeros(res);
        return res;
    };

    string out;
    if (negA == negB) {
        out = addAbs(a, b);
        if (negA && out != "0") out = "-" + out;
    } else {
        int c = cmpAbs(a, b);
        if (c == 0) {
            out = "0";
        } else if (c > 0) {
            out = subAbs(a, b);
            if (negA) out = "-" + out;
        } else {
            out = subAbs(b, a);
            if (negB) out = "-" + out;
        }
    }

    cout << out << "\n";
    return 0;
}