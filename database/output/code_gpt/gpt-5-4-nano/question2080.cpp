/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

static int64 countHolesDigits(int d) {
    if (d == 0) return 1;
    if (d == 4) return 1;
    if (d == 6) return 1;
    if (d == 8) return 2;
    if (d == 9) return 1;
    return 0;
}

static int64 countHoles(i128 n) {
    if (n < 0) n = -n;
    if (n == 0) return 1;
    int64 total = 0;
    while (n > 0) {
        int d = (int)(n % 10);
        total += countHolesDigits(d);
        n /= 10;
    }
    return total;
}

static bool isPrime64(int64 x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    if (x % 3 == 0) return x == 3;
    for (i128 i = 5; i*i <= x; i += 6) {
        if (x % (int64)i == 0 || x % (int64)(i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    i128 n = 0;
    bool neg = false;
    int idx = 0;
    if (!s.empty() && s[0] == '-') { neg = true; idx = 1; }
    for (; idx < (int)s.size(); idx++) n = n * 10 + (s[idx] - '0');
    if (neg) n = -n;

    int64 holes = countHoles(n);
    cout << (isPrime64(holes) ? 'S' : 'N');
    return 0;
}