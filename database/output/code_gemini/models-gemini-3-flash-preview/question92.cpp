/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef __uint128_t uint128;

uint128 reverseUint128(uint128 n) {
    uint128 res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n /= 10;
    }
    return res;
}

string uint128ToString(uint128 n) {
    if (n == 0) return "0";
    string s = "";
    while (n > 0) {
        s += (char)((n % 10) + '0');
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s;
        if (!(cin >> s)) break;
        
        uint128 n = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0');
            }
        }

        int iterations = 0;
        while (iterations < 1000) {
            uint128 rev = reverseUint128(n);
            if (n == rev) break;
            n += rev;
            iterations++;
        }
        
        cout << iterations << " " << uint128ToString(n) << "\n";
    }

    return 0;
}