/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

float CalculaHospedagem(const string& tipoApartamento, int dias) {
    float valorDiaria;
    if (tipoApartamento == "individual") {
        valorDiaria = 125.0;
    } else if (tipoApartamento == "suite dupla") {
        valorDiaria = 140.0;
    } else if (tipoApartamento == "suite tripla") {
        valorDiaria = 180.0;
    } else {
        return 0.0; // Tipo de apartamento inválido
    }
    
    float total = valorDiaria * dias;
    if (dias >= 3) {
        total *= 0.85; // 15% de desconto
    }
    
    return total;
}

int main() {
    string tipoApartamento;
    int dias;
    
    cin >> tipoApartamento;
    cin >> dias;
    
    float valorTotal = CalculaHospedagem(tipoApartamento, dias);
    cout << fixed << setprecision(2) << valorTotal << endl;
    
    return 0;
}
