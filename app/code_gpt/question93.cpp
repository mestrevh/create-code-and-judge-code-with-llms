/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int altura, n;
    while (true) {
        cin >> altura >> n;
        if (altura == 0 && n == 0) break;

        int totalGatos = 0;
        int somaAltura = 0;
        int alturaAtual = altura;

        while (alturaAtual > 1) {
            totalGatos += (alturaAtual / (n + 1));
            somaAltura += alturaAtual;
            alturaAtual /= (n + 1);
        }

        somaAltura += totalGatos; // consideramos os gatos de altura 1
        cout << totalGatos << " " << somaAltura << endl;
    }
    return 0;
}
