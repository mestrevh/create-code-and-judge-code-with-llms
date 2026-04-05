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
    if (!(cin >> A)) return 0;
    if (!(cin >> B)) return 0;
    
    double media = (A * 3.5 + B * 7.5) / 11.0;
    cout << "MEDIA = " << fixed << setprecision(5) << media << "\n";
    return 0;
}