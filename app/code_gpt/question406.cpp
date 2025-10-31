/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, soma = 0;
    cin >> a >> b;
    int inicio = min(a, b);
    int fim = max(a, b);

    for (int i = inicio; i <= fim; i++) {
        if (i > 0) {
            soma += i;
        }
    }
    
    cout << soma << endl;
    return 0;
}
