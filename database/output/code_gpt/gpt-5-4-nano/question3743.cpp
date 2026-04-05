/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    double media = (n1 + n2 + n3) / 3.0;
    double mediaP1 = (2*n1 + 2*n2 + 3*n3) / 7.0;
    double mediaP2 = (1*n1 + 2*n2 + 2*n3) / 5.0;

    cout << fixed << setprecision(2);
    cout << media << "\n" << mediaP1 << "\n" << mediaP2 << "\n";
    return 0;
}