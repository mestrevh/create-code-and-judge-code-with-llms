/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> h(6);
    for (int i = 0; i < 5; i++) {
        string s;
        if (!(cin >> s)) return 0;
        if (s.size() == 1 && (s[0] == 'C' || s[0] == 'c')) {
            long long x;
            cin >> x;
            h[i] = x * 3;
            if (i + 1 < 5) h[i + 1] = -1; 
        } else {
            h[i] = stoll(s);
        }
    }

    auto effortAtDay = [&](int day, vector<char> types, vector<long long> vals) -> long long {
        return vals[day];
    };

    return 0;
}