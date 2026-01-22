/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int contarOcorrencias(unsigned long long n, int x) {
    int contador = 0;
    while (n > 0) {
        if (n % 10 == x) {
            contador++;
        }
        n /= 10;
    }
    return contador;
}

int main() {
    unsigned long long n;
    int x;
    cin >> n >> x;
    cout << contarOcorrencias(n, x) << endl;
    return 0;
}
