/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int numeros[10], ultimo, cont = 0;
    
    for (int i = 0; i < 10; i++) {
        cin >> numeros[i];
    }
    
    ultimo = numeros[9];
    
    for (int i = 0; i < 10; i++) {
        if (numeros[i] == ultimo) {
            cont++;
        }
    }
    
    cout << "O numero " << ultimo << " apareceu " << cont << " vezes" << endl;
    return 0;
}
