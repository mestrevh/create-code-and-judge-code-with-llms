/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    if (!(cin >> N)) return 0;
    
    for (int i = 1; i <= 10; i++) {
        cout << N * i;
        if (i < 10) cout << "\n";
    }
    return 0;
}