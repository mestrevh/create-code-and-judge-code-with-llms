/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> carrinhos;
    int numero;

    while (true) {
        cin >> numero;
        if (numero == -1) break;
        carrinhos.push_back(numero);
    }

    int sorteado;
    cin >> sorteado;

    for (size_t i = 0; i < carrinhos.size(); ++i) {
        if (carrinhos[i] == sorteado) {
            cout << "O bilhete sorteado e o " << sorteado << " e esta no carrinho " << i + 1 << endl;
            return 0;
        }
    }

    cout << "Nenhum carrinho foi sorteado" << endl;
    return 0;
}
