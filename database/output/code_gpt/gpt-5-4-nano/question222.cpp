/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long Cv, Ce, Cs, Fv, Fe, Fs;
    if (!(cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs)) return 0;
    
    long long Cpoints = 3 * Cv + Ce;
    long long Fpoints = 3 * Fv + Fe;
    
    if (Cpoints > Fpoints) cout << 'C';
    else if (Fpoints > Cpoints) cout << 'F';
    else {
        if (Cs > Fs) cout << 'C';
        else if (Fs > Cs) cout << 'F';
        else cout << '=';
    }
    return 0;
}