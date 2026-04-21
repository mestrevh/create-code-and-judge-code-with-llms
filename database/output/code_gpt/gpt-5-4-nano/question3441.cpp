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
    
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < i; s++) cout << ' ';
        for (int j = i; j < n; j++) {
            cout << (j + 1);
            if (j + 1 < n) cout << ' ';
        }
        if (i + 1 < n) cout << '\n';
    }
    return 0;
}