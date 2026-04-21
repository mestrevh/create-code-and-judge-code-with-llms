/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long L, D;
    long long K, P;
    if (!(cin >> L >> D)) return 0;
    cin >> K >> P;
    
    long long ped = L / D;
    long long total = L * K + ped * P;
    cout << total << "\n";
    return 0;
}