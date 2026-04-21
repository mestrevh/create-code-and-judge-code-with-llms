/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    vector<long long> v = {a, b, c};
    for (int i = 0; i < 2; ++i) {
        int mx = i;
        for (int j = i + 1; j < 3; ++j)
            if (v[j] > v[mx]) mx = j;
        swap(v[i], v[mx]);
    }

    cout << v[0] << "\n" << v[1] << "\n" << v[2];
    return 0;
}