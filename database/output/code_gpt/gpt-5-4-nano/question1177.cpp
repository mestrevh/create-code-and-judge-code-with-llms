/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long P, S, T;
    if (!(cin >> P >> S >> T)) return 0;
    long long a[3] = {P, S, T};
    
    bool hasZero = false;
    bool hasGreaterThanTen = false;
    bool hasEven = false;
    
    for (int i = 0; i < 3; i++) {
        if (a[i] == 0) hasZero = true;
        if (a[i] > 10) hasGreaterThanTen = true;
        if (a[i] != 0 && a[i] % 2 == 0) hasEven = true;
    }
    
    bool defeated = !hasZero && hasGreaterThanTen && hasEven;
    cout << (defeated ? "Sim" : "Nao");
    return 0;
}