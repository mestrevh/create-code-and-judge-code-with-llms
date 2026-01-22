/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double peso, total = 0;
    int cont = 0;
    const double capacidade = 18.0;

    cout << "Insira o peso dos livros:" << endl;

    while (true) {
        cin >> peso;
        if (total + peso > capacidade) break;
        total += peso;
        cont++;
    }

    cout << "Podem ser carregados " << cont << " livros." << endl;
    return 0;
}
