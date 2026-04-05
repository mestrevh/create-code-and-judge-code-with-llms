/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    
    if (n < 4) {
        cout << 0 << "\n";
        return 0;
    }
    
    long long diagonals = n * (n - 3) / 2;
    cout << diagonals << "\n";
    return 0;
}