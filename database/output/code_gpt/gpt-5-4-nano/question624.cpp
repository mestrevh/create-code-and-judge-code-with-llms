/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, bx;
    if (!(cin >> n >> bx)) return 0;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    int m, by;
    cin >> m >> by;

    vector<int> y(m);
    for (int i = 0; i < m; i++) cin >> y[i];

    vector<int> xd = x, yd = y;

    auto compareByLog = [&](const vector<int>& a, int baseA, const vector<int>& b, int baseB) -> int {
        long double la = 0, lb = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            la = la * baseA + a[i];
            if (la > 1e300L) break;
        }
        for (int i = 0; i < (int)b.size(); i++) {
            lb = lb * baseB + b[i];
            if (lb > 1e300L) break;
        }
        if (la < lb) return -1;
        if (la > lb) return 1;
        return 0;
    };

    vector<int> maxDigits = x;
    vector<int> otherDigits = y;

    int sizeMax = max(n, m);
    int i = 0, j = 0;

    vector<int> A = x, B = y;

    int cmpLen = 0;
    if (n != m) {
        long double logA = (long double)(n - 1) * log((long double)bx) + log((long double)A[0]);
        long double logB = (long double)(m - 1) * log((long double)by) + log((long double)B[0]);
        if (fabsl(logA - logB) > 1e-12L) {
            if (logA < logB) cmpLen = -1;
            else cmpLen = 1;
        }
    }

    auto toBig = [&](const vector<int>& digits, int base) {
        vector<int> out;
        out.reserve(1000);
        out.push_back(0);
        for (int d : digits) {
            int carry = d;
            for (size_t k = 0; k < out.size(); k++) {
                long long v = 1LL * out[k] * base + carry;
                out[k] = (int)(v % 1000000000LL);
                carry = (int)(v / 1000000000LL);
            }
            while (carry) {
                out.push_back(carry % 1000000000LL);
                carry /= 1000000000LL;
            }
        }
        while (out.size() > 1 && out.back() == 0) out.pop_back();
        return out;
    };

    if (cmpLen == 0) {
        auto bigX = toBig(x, bx);
        auto bigY = toBig(y, by);
        if (bigX.size() != bigY.size()) {
            cout << (bigX.size() < bigY.size() ? '<' : '>') << "\n";
            return 0;
        }
        for (int k = (int)bigX.size() - 1; k >= 0; k--) {
            if (bigX[k] != bigY[k]) {
                cout << (bigX[k] < bigY[k] ? '<' : '>') << "\n";
                return 0;
            }
        }
        cout << "=\n";
        return 0;
    } else {
        cout << (cmpLen < 0 ? '<' : '>') << "\n";
    }
    return 0;
}