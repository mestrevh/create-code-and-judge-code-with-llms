/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool first = true;
    long long prod_ll = 1;

    __int128 prod128 = 1;
    bool overflowed = false;

    long long x;
    while (cin >> x) {
        if (first) {
            first = false;
            prod_ll = x;
            prod128 = x;
        } else {
            if (!overflowed) {
                __int128 check = (__int128)prod_ll * (__int128)x;
                if (check > LLONG_MAX || check < LLONG_MIN) overflowed = true;
                if (!overflowed) prod_ll = (long long)check;
                else prod128 = prod128 * (__int128)x;
            } else {
                prod128 = prod128 * (__int128)x;
            }
        }
    }

    if (first) {
        return 0;
    }

    cout << "Prod = ";
    if (overflowed) {
        __int128 v = prod128;
        bool neg = v < 0;
        if (neg) v = -v;
        string s;
        while (v > 0) {
            int digit = (int)(v % 10);
            s.push_back('0' + digit);
            v /= 10;
        }
        if (s.empty()) s = "0";
        if (neg) s.push_back('-');
        reverse(s.begin(), s.end());
        cout << s;
    } else {
        cout << prod_ll;
    }
    cout << "\n";
    return 0;
}