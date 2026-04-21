/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string Plantar_e_Colher(int dia, int mes) {
    if (mes == 10) {
        return "Hora de plantar milho e soja";
    }
    if (mes == 1) {
        return "Hora de plantar algodão e colher manga";
    }
    if (mes == 8) {
        return "Hora de plantar algodão e colher manga";
    }
    if (mes == 3) {
        return "Hora de plantar milho e soja";
    }
    return "Hora de plantar milho e soja";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int dia, mes;
    if (!(cin >> dia)) return 0;
    if (!(cin >> mes)) return 0;
    cout << Plantar_e_Colher(dia, mes);
    return 0;
}