/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> numeros(101);
    cout << "Digite a sequencia de numero:\n";
    
    for (int i = 0; i < 101; ++i) {
        cin >> numeros[i];
    }
    
    double ultimoNumero = numeros[100];
    cout << "Indice no qual o numero desejado aparece:\n";
    
    for (int i = 0; i < 100; ++i) {
        if (numeros[i] == ultimoNumero) {
            cout << i << '\n';
        }
    }
    
    return 0;
}
