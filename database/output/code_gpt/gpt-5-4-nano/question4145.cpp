/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long qtd, k;
    if (!(cin >> qtd >> k)) return 0;
    __int128 ans = 1 + (__int128)qtd * (__int128)k;
    long long out = (long long)ans;
    cout << out;
    return 0;
}