/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ig, ia, enc, ind, st;
    if (!(cin >> ig >> ia >> enc >> ind >> st)) return 0;
    
    bool requisito1 = (ig == 1 || ia == 1);
    bool requisito2 = (enc == 1 && ind == 1);
    bool requisito3 = (st == 1);
    
    if (requisito1 && requisito2 && requisito3) cout << "AVALIADO\n";
    else cout << "0\n";
    
    return 0;
}