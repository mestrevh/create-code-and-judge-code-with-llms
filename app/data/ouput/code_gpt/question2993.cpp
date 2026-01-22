/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    int contador = 0;
    for (int i = 1; x * i < n; i++) {
        contador++;
    }
    cout << "O numero " << x << " tem " << contador << " multiplos menores que " << n << "." << endl;
    return 0;
}
