/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void imprimirPares(int n) {
    if (n < 0) return;
    cout << n << endl;
    imprimirPares(n - 2);
}

int main() {
    int N;
    cin >> N;
    if (N % 2 != 0) N--; // Garantir que N é par
    imprimirPares(N);
    return 0;
}
