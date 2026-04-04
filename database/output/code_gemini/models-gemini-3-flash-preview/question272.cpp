/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long ll;

struct BigInt {
    int sign;
    vector<ll> d;
    static const ll BASE = 1000000000;

    void trim() {
        while (d.size() > 1 && d.back() == 0) d.pop_back();
        if (d.empty()) {
            d.push_back(0);
            sign = 1;
        }
        if (d.size() == 1 && d[0] == 0) sign = 1;
    }

    BigInt(string s) {
        if (s.empty()) {
            sign = 1;
            d.push_back(0);
            return;
        }
        int start = 0;
        if (s[0] == '-') {
            sign = -1;
            start = 1;
        } else if (s[0] == '+') {
            sign = 1;
            start = 1;
        } else {
            sign = 1;
        }
        for (int i = (int)s.size(); i > start; i -= 9) {
            if (i < 9 + start)
                d.push_back(stoll(s.substr(start, i - start)));
            else
                d.push_back(stoll(s.substr(i - 9, 9)));
        }
        trim();
    }

    BigInt(ll v = 1) {
        if (v == 0) {
            sign = 1;
            d.assign(1, 0);
        } else {
            if (v < 0) {
                sign = -1;
                v = -v;
            } else {
                sign = 1;
            }
            while (v > 0) {
                d.push_back(v % BASE);
                v /= BASE;
            }
        }
        trim();
    }

    void multiply(const BigInt& other) {
        if ((d.size() == 1 && d[0] == 0) || (other.d.size() == 1 && other.d[0] == 0)) {
            sign = 1;
            d.assign(1, 0);
            return;
        }
        int target_sign = sign * other.sign;
        vector<ll> res(d.size() + other.d.size(), 0);
        for (size_t i = 0; i < d.size(); ++i) {
            if (d[i] == 0) continue;
            ll carry = 0;
            for (size_t j = 0; j < other.d.size() || carry; ++j) {
                ll cur = res[i + j] +
                         d[i] * (j < other.d.size() ? other.d[j] : 0) +
                         carry;
                res[i + j] = cur % BASE;
                carry = cur / BASE;
            }
        }
        d = res;
        sign = target_sign;
        trim();
    }

    void print() {
        if (sign == -1) cout << "-";
        cout << d.back();
        for (int i = (int)d.size() - 2; i >= 0; --i) {
            cout << setfill('0') << setw(9) << d[i];
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;
    
    BigInt res(s);
    while (cin >> s) {
        res.multiply(BigInt(s));
    }
    
    cout << "Prod = ";
    res.print();

    return 0;
}