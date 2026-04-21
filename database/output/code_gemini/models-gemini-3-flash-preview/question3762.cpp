/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef __int128 int128;

int128 stringTo128(const string& s) {
    if (s.empty()) return 0;
    int128 res = 0;
    int sign = 1;
    size_t i = 0;
    if (s[0] == '-') {
        sign = -1;
        i = 1;
    }
    for (; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
        }
    }
    return res * sign;
}

string stringFrom128(int128 n) {
    if (n == 0) return "0";
    bool neg = false;
    if (n < 0) {
        neg = true;
        n = -n;
    }
    string s;
    s.reserve(40);
    while (n > 0) {
        s += (char)('0' + (int)(n % 10));
        n /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int128 totalSum = 0;
    string s;
    for (int i = 0; i < N; ++i) {
        if (cin >> s) {
            totalSum += stringTo128(s);
        }
    }

    cout << stringFrom128(totalSum) << endl;

    return 0;
}