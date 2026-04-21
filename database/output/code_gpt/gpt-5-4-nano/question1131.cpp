/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    auto encrypt = [&](const string& x) -> string {
        string r = x;
        reverse(r.begin(), r.end());
        for (size_t i = 0; i + 1 < r.size(); i += 2) {
            swap(r[i], r[i + 1]);
        }
        return r;
    };

    auto decrypt = [&](const string& x) -> string {
        string r = x;
        for (size_t i = 0; i + 1 < r.size(); i += 2) {
            swap(r[i], r[i + 1]);
        }
        reverse(r.begin(), r.end());
        return r;
    };

    cout << encrypt(s) << "\n" << decrypt(t) << "\n";
    return 0;
}