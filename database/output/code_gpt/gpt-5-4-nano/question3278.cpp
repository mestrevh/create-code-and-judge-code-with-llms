/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n;
    if (!(cin >> n)) return 0;

    if (n > 7.0) cout << "bolinha verde";
    else if (n >= 5.0) cout << "bolinha amarela";
    else cout << "bolinha vermelha";
    return 0;
}