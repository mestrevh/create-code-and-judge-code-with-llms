/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int somaDivisores(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }
    return soma;
}

int main() {
    int numeros[5], maiorSoma = 0, resultado = 0;
    for (int i = 0; i < 5; i++) {
        cin >> numeros[i];
    }

    for (int i = 0; i < 5; i++) {
        int soma = somaDivisores(numeros[i]);
        if (soma > maiorSoma) {
            maiorSoma = soma;
            resultado = numeros[i];
        }
    }
    
    cout << resultado << endl;
    return 0;
}
