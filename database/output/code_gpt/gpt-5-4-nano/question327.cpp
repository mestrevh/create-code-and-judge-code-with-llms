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
    
    for (long long i = 1; i <= N; i++) {
        cout << i << " " << i * i << " " << i * i * i << "\n";
        cout << i << " " << i * i + 1 << " " << i * i * i + 1 << "\n";
    }
    return 0;
}