/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long idade;
    if (!(cin >> idade)) return 0;
    
    if (idade >= 18) cout << "maior de idade";
    else cout << "menor de idade";
    return 0;
}