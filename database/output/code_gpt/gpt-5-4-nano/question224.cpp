/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x;
    int mx = -1;
    while (cin >> x) {
        if (x == 0) break;
        if (x > mx) mx = x;
    }
    if (mx != -1) cout << mx;
    return 0;
}