/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    string s;
    while (cin >> s) {
        if (!s.empty() && (s[0] == 'x' || s == "x")) break;
        a.push_back(stoll(s));
    }

    bool crescente = true;
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) {
            crescente = false;
            break;
        }
    }

    if (!crescente) {
        cout << "false";
        return 0;
    }

    long long n = (long long)a.size();
    if (n == 0) {
        cout << "true\n0";
        return 0;
    }

    long long sum = 0;
    for (auto v : a) sum += v;

    long long firstIdx = 0;
    for (long long i = 0; i < n; i++) {
        __int128 lhs = (__int128)a[i] * n;
        __int128 rhs = (__int128)sum;
        if (lhs >= rhs) {
            firstIdx = i;
            break;
        }
    }

    cout << "true\n" << firstIdx;
    return 0;
}