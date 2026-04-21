/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A;
    if (!(cin >> A)) return 0;
    long long period = 76;
    long long last1986 = 1986;
    long long nextYear = last1986 + ((A < last1986) ? 0 : ((A - last1986) / period + 1) * period);
    cout << nextYear << "\n";
    return 0;
}