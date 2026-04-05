/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x;
    if (!(cin >> x)) return 0;
    
    if (x == 1) cout << "Nordeste";
    else if (x == 2) cout << "Norte";
    else if (x == 3 || x == 4) cout << "Centro-Oeste";
    else if (x >= 5 && x <= 9) cout << "Sul";
    else if (x >= 10 && x <= 15) cout << "Sudeste";
    
    return 0;
}