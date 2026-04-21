/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long T;
    long long C;
    if (!(cin >> T >> C)) return 0;
    
    long long dayTicks = 24000;
    long long safeTicksPerDay = 12000;
    long long total = T * C;
    
    long long days = (total + safeTicksPerDay - 1) / safeTicksPerDay;
    cout << days << "\n";
    return 0;
}