/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long D, VF, VG;
    while (cin >> D >> VF >> VG) {
        if (D == -1 && VF == -1 && VG == -1) break;
        long long tF = (3 * D) / 2;
        bool ok = (tF <= D * (3 * VG) / (2 * VF));
        cout << (ok ? 'S' : 'N') << "\n";
    }
    return 0;
}