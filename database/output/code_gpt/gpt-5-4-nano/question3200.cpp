/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double raio, altura;
    if (!(cin >> raio >> altura)) return 0;
    long double volume = acosl(-1.0L) * raio * raio * altura;
    cout << setprecision(15) << (double)volume;
    return 0;
}