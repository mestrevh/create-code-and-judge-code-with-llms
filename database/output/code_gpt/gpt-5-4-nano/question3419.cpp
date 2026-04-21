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
    
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << 0 << "\n";
        } else if (i == 1) {
            cout << 1 << "\n";
        } else {
            long long c = a + b;
            cout << c << "\n";
            a = b;
            b = c;
        }
    }
    return 0;
}