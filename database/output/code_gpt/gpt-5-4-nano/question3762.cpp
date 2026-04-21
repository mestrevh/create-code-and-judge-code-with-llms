/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];

    string sumAbs = "0";
    bool neg = false;

    auto cmpAbs = [&](const string& a, const string& b) -> int {
        if (a.size() != b.size()) return (a.size() < b.size()) ? -1 : 1;
        if (a == b) return 0;
        return (a < b) ? -1 : 1;
    };

    auto strip = [&](string s) -> string {
        int i = 0;
        while (i + 1 < (int)s.size() && s[i] == '0') i++;
        s.erase(0, i);
        return s;
    };

    auto addAbs = [&](const string& a, const string& b) -> string {
        int i = (int)a.size() - 1, j = (int)b.size() - 1;
        int carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? a[i--] - '0' : 0;
            int y = (j >= 0) ? b[j--] - '0' : 0;
            int s = x + y + carry;
            res.push_back(char('0' + (s % 10)));
            carry = s / 10;
        }
        reverse(res.begin(), res.end());
        return strip(res);
    };

    auto subAbs = [&](const string& a, const string& b) -> string {
        string aa = a, bb = b;
        if (cmpAbs(aa, bb) < 0) swap(aa, bb);
        int i = (int)aa.size() - 1, j = (int)bb.size() - 1;
        int borrow = 0;
        string res;
        while (i >= 0) {
            int x = aa[i--] - '0' - borrow;
            int y = (j >= 0) ? (bb[j--] - '0') : 0;
            if (x < y) {
                x += 10;
                borrow = 1;
            } else borrow = 0;
            int d = x - y;
            res.push_back(char('0' + d));
        }
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return strip(res.empty() ? string("0") : res);
    };

    auto isZero = [&](const string& s) -> bool {
        for (char c : s) if (c != '0') return false;
        return true;
    };

    sumAbs = "0";
    bool sumNeg = false;

    for (int i = 0; i < N; i++) {
        string m = nums[i];
        bool xNeg = false;
        if (!m.empty() && m[0] == '-') {
            xNeg = true;
            m.erase(m.begin());
        }
        m = strip(m.empty() ? string("0") : m);

        if (isZero(m)) continue;

        if (isZero(sumAbs)) {
            sumAbs = m;
            sumNeg = xNeg;
            continue;
        }

        if (sumNeg == xNeg) {
            sumAbs = addAbs(sumAbs, m);
        } else {
            int c = cmpAbs(sumAbs, m);
            if (c == 0) {
                sumAbs = "0";
                sumNeg = false;
            } else if (c > 0) {
                sumAbs = subAbs(sumAbs, m);
            } else {
                sumAbs = subAbs(m, sumAbs);
                sumNeg = xNeg;
            }
        }
    }

    sumAbs = strip(sumAbs);
    if (isZero(sumAbs)) {
        cout << "0\n";
    } else {
        if (sumNeg) cout << '-';
        cout << sumAbs << "\n";
    }
    return 0;
}