/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double A, B;
    if (!(cin >> A >> B)) return 0;
    double x = -B / A;
    cout << fixed << setprecision(2) << x;
    return 0;
}