/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long caixas;
    if (!(cin >> caixas)) return 0;
    
    long long comprimidos = caixas * 35;
    long long por_dia = 4;
    
    long long dias = comprimidos / por_dia;
    long long sobra = comprimidos % por_dia;
    
    cout << dias << "\n" << sobra << "\n";
    return 0;
}