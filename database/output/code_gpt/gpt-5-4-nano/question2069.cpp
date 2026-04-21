/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, g, p;
    if (!(cin >> a >> g >> p)) return 0;

    long long x = 0;
    long long v = 0;
    long long fuel = g;
    long long dist = 0;

    while (true) {
        if (x >= p) {
            cout << dist << "\n" << "S\n";
            return 0;
        }
        if (fuel < v) {
            cout << dist << "\n" << "N\n";
            return 0;
        }
        fuel -= v;
        v += a;
        x += v;
        dist += v;
    }
}