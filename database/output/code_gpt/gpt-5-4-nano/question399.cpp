/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

float CalculaHospedagem(const string& tipo, int dias) {
    double preco = 0.0;
    if (tipo == "individual") preco = 125.0;
    else if (tipo == "Suíte dupla" || tipo == "Sute dupla" || tipo == "Suite dupla") preco = 140.0;
    else if (tipo == "Suíte tripla" || tipo == "Sute tripla" || tipo == "Suite tripla") preco = 180.0;
    double total = preco * dias;
    if (dias >= 3) total *= 0.85;
    return (float)total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string tipo;
    int dias;
    getline(cin, tipo);
    while (tipo.size() && (tipo.back()=='\r' || tipo.back()=='\n')) tipo.pop_back();
    cin >> dias;
    
    cout.setf(ios::fixed);
    cout << setprecision(2) << CalculaHospedagem(tipo, dias);
    return 0;
}