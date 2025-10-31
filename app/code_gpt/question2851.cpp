/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros(10);
    vector<int> pares;

    cout << "Digite os 10 numeros inteiros:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> numeros[i];
        if (numeros[i] % 2 == 0) {
            pares.push_back(numeros[i]);
        }
    }

    cout << "Numeros pares na ordem inversa:" << endl;
    for (int i = pares.size() - 1; i >= 0; i--) {
        cout << pares[i] << (i == 0 ? "" : " ");
    }
    return 0;
}
