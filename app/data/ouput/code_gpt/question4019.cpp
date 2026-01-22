/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

unsigned long long fatorial(int n) {
    if (n == 0) return 1;
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int n;
    cin >> n;
    cout << fatorial(n) << endl;
    return 0;
}
