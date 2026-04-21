/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        unsigned long long A, B;
        cin >> A >> B;
        unsigned long long x = A ^ B;
        cout << __builtin_popcountll(x) << "\n";
    }
    return 0;
}