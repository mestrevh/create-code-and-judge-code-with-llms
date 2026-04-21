/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int soma = 0;
    for (int i = 0; i <= 500; i += 2) {
        soma += i;
    }

    cout << "Soma dos pares de 0 a 500: " << soma << endl;

    return 0;
}