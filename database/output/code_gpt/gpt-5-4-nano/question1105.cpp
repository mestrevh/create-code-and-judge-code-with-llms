/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> a(10);
    long long x;
    for (int i = 0; i < 10; i++) {
        if (!(cin >> a[i])) return 0;
    }

    long long mx = a[0];
    for (int i = 1; i < 10; i++) mx = max(mx, a[i]);

    long long sumIdx = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] == mx) sumIdx += i;
    }

    cout << sumIdx << "\n";
    return 0;
}