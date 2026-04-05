/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x;
    if (!(cin >> x)) return 0;
    long long y = x * x - 2 * x - 2;
    cout << y << "\n";
    return 0;
}