/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double F;
    if (!(cin >> F)) return 0;
    double C = (F - 32.0) * 5.0 / 9.0;
    cout.setf(ios::fixed);
    cout << setprecision(2) << C;
    return 0;
}