/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long value;
    bool hasAny = false;
    long long mn = 0, mx = 0;

    vector<long long> numbers;
    while (cin >> value) {
        if (value == -1) break;
        numbers.push_back(value);
        if (!hasAny) {
            mn = mx = value;
            hasAny = true;
        } else {
            mn = min(mn, value);
            mx = max(mx, value);
        }
        cout << "menor=" << mn << "||MAIOR=" << mx << "\n";
    }

    if (!hasAny) return 0;

    bool first = true;
    for (long long k = mn; k <= mx; ) {
        if (k < mn) k = mn;
        if (k == 0) {
            if (mn == 0) {
                if (first) {
                    cout << 0;
                    first = false;
                } else {
                    cout << "||" << 0;
                }
                break;
            }
        }
        if (mn == 0) break;
        if (k == 0) break;
        if (k >= mn && k <= mx) {
            if (first) {
                cout << k;
                first = false;
            } else {
                cout << "||" << k;
            }
        }
        if (mn == 0) break;
        if (k > (mx - mn)) break;
        k += mn;
    }

    if (mn == 0) {
        if (first) cout << "0";
    }

    if (mn != 0) {
        long long start = 0;
        if (mn != 0) {
            long long mult = mn;
            long long t = mn;
            if (t == 0) t = 0;
            vector<long long> out;
        }
    }

    if (hasAny) {
        vector<long long> multiples;
        if (mn == 0) {
            if (mx >= 0) multiples.push_back(0);
        } else {
            for (long long m = mn; m <= mx; m += mn) multiples.push_back(m);
        }
        if (!multiples.empty()) {
            first = true;
            for (size_t i = 0; i < multiples.size(); i++) {
                if (i) cout << "||";
                cout << multiples[i];
            }
        }
    }
    return 0;
}