/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long Q, R, S;
    if (!(cin >> Q >> R >> S)) return 0;
    long long x = Q + (S - 1) * R;
    cout << "Na semana " << S << " Soneca tera que fazer " << x << " questoes!";
    return 0;
}