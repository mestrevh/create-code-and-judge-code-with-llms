/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;

    long long i1, f1, i2, f2;
    if (!(cin >> i1 >> f1 >> i2 >> f2)) return 0;

    int n = (int)s.size();
    auto getSlice = [&](long long l, long long r) -> string {
        if (l < 0) l = 0;
        if (r >= n) r = n - 1;
        if (l > r) return "";
        return s.substr((size_t)l, (size_t)(r - l + 1));
    };

    string s1 = getSlice(i1, f1);
    string s2 = getSlice(i2, f2);
    cout << s1 << s2;
    return 0;
}