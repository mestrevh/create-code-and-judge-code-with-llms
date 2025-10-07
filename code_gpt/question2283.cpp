/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int somaDigitos(unsigned int n) {
    if (n == 0) return 0;
    return (n % 10) + somaDigitos(n / 10);
}

int main() {
    unsigned int n;
    cin >> n;
    cout << somaDigitos(n) << endl;
    return 0;
}
