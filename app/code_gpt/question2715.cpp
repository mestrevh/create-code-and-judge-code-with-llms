/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int soma = 0;
    for (int i = 0; i <= 500; i += 2) {
        soma += i;
    }
    cout << "Soma dos pares de 0 a 500: " << soma << endl;
    return 0;
}
