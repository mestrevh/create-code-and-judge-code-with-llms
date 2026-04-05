/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long hp, atk, rhp, ratk;
    if (!(cin >> hp >> atk)) return 0;
    cin >> rhp >> ratk;
    
    __int128 lhs = (__int128)hp * atk;
    __int128 rhs = (__int128)rhp * ratk;
    
    if (lhs > rhs) cout << "Matei um rathound\n";
    else cout << "Fugi de um rathound\n";
    return 0;
}