/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long L, A, P, R;
    if (!(cin >> L >> A >> P >> R)) return 0;
    
    long double diag = sqrt((long double)L*L + (long double)A*A + (long double)P*P);
    long double radiusNeeded = diag / 2.0L;
    
    cout << (radiusNeeded <= (long double)R + 1e-12L ? 'S' : 'N');
    return 0;
}