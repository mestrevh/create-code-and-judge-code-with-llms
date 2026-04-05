/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long A, B;
    if (!(cin >> A)) return 0;
    if (!(cin >> B)) return 0;
    
    for (unsigned long long x = A; x > B; --x) {
        if (x == A || x == B) continue;
        cout << x << "\n";
    }
    return 0;
}