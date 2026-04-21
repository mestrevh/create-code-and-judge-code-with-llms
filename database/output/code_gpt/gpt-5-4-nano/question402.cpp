/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string EstacaoAno(int dia, int mes) {
    if ((mes == 3 && dia >= 21) || (mes >= 4 && mes <= 5) || (mes == 6 && dia <= 20)) return "OUTONO";
    if ((mes == 6 && dia >= 21) || (mes >= 7 && mes <= 8) || (mes == 9 && dia <= 20)) return "INVERNO";
    if ((mes == 12 && dia >= 21) || (mes == 1) || (mes >= 2 && mes <= 2) || (mes == 3 && dia <= 20)) return "VERAO";
    return "PRIMAVERA";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int dia, mes;
    if (!(cin >> dia >> mes)) return 0;
    cout << EstacaoAno(dia, mes);
    return 0;
}