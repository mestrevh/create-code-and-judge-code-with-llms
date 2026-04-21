/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) cout << i;
        if (i < n) cout << "\n";
    }
    return 0;
}