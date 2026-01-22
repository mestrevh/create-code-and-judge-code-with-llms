/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int calcularPrimeiroDigito(const vector<int>& numeros) {
    int soma = 0;
    for (int j = 1; j <= 9; j++) {
        soma += numeros[j - 1] * (11 - j);
    }
    int resto = soma % 11;
    return (resto < 2) ? 0 : 11 - resto;
}

int calcularSegundoDigito(const vector<int>& numeros, int primeiroDigito) {
    int soma = 0;
    for (int j = 1; j <= 10; j++) {
        soma += (j <= 9 ? numeros[j - 1] : primeiroDigito) * (12 - j);
    }
    int resto = soma % 11;
    return (resto < 2) ? 0 : 11 - resto;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        vector<int> numeros(9);
        for (int j = 0; j < 9; j++) {
            cin >> numeros[j];
        }

        int primeiroDigito = calcularPrimeiroDigito(numeros);
        int segundoDigito = calcularSegundoDigito(numeros, primeiroDigito);
        
        cout << "Caso " << i << ": ";
        for (int num : numeros) {
            cout << num;
        }
        cout << primeiroDigito << segundoDigito << endl;
    }

    return 0;
}
