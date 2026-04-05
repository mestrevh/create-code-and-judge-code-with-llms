/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M;
    if (!(cin >> M)) return 0;

    if (M == 0) {
        cout << "Armstrong";
        return 0;
    }

    string s = to_string(llabs(M));
    int n = (int)s.size();

    long long sum = 0;
    long long x = llabs(M);

    for (char c : s) {
        int d = c - '0';
        long long p = 1;
        for (int i = 0; i < n; i++) p *= d;
        sum += p;
        if (sum > LLONG_MAX / 2) break;
    }

    if (sum == llabs(M)) cout << "Armstrong";
    else cout << "soma: " << sum;

    return 0;
}