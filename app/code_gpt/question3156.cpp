/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int somaDivisores(int n) {
    int soma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) soma += i;
    }
    return soma;
}

int main() {
    int i, j;
    cin >> i >> j;
    for (int x = i; x <= j; x++) {
        if (somaDivisores(x) == x + 1) {
            cout << x << endl;
        }
    }
    return 0;
}
