/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double X, Y;
    if (!(cin >> X >> Y)) return 0;
    double media = (X + Y) / 2.0;
    cout.setf(ios::fixed);
    cout << setprecision(2) << media;
    return 0;
}