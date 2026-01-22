/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int numeros[5];
    
    for (int i = 0; i < 5; i++) {
        cout << "Digite um numero inteiro:" << endl;
        cin >> numeros[i];
    }
    
    for (int i = 0; i < 5; i++) {
        cout << "Numero " << (i + 1) << ": " << numeros[i] << endl;
    }
    
    return 0;
}
