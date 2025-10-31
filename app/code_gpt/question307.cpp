/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double N;
    cin >> N;
    
    int notas[6] = {10000, 5000, 2000, 1000, 500, 200};
    double moedas[6] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
    
    int valor = N * 100; // Convertendo para centavos
    cout << "NOTAS:" << endl;
    for (int i = 0; i < 6; i++) {
        int quantidade = valor / notas[i];
        valor %= notas[i];
        cout << quantidade << " nota(s) de R$ " << fixed << setprecision(2) << notas[i] / 100.0 << endl;
    }
    
    cout << "MOEDAS:" << endl;
    for (int i = 0; i < 6; i++) {
        int quantidade = valor / (moedas[i] * 100);
        valor %= (moedas[i] * 100);
        cout << quantidade << " moeda(s) de R$ " << fixed << setprecision(2) << moedas[i] << endl;
    }
    
    return 0;
}
