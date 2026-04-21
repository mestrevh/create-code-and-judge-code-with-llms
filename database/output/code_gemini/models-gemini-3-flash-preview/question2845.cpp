/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Insira o peso dos livros:" << endl;

    double peso_atual;
    double soma_total = 0.0;
    int contador = 0;

    while (cin >> peso_atual) {
        if (soma_total + peso_atual <= 18.0) {
            soma_total += peso_atual;
            contador++;
        } else {
            break;
        }
    }

    cout << "Podem ser carregados " << contador << " livros." << endl;

    return 0;
}