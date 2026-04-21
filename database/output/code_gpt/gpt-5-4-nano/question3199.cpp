/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double a, b;
    if (!(cin >> a >> b)) return 0;
    long double res = a / b;
    cout.setf(ios::fixed);
    cout << setprecision(6) << (double)res;
    return 0;
}