/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long T1, T2, T3, T4;
    if (!(cin >> T1 >> T2 >> T3 >> T4)) return 0;
    vector<long long> T = {T1, T2, T3, T4};
    sort(T.begin(), T.end());
    
    long long ans = T[0] + 1;
    for (int i = 1; i < 4; i++) ans *= (T[i] + 1);
    cout << ans << "\n";
    return 0;
}