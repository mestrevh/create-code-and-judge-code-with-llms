/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int decrementa(int n) {
    if (n == 0) return 0;
    int primeiroDigito = to_string(n)[0] - '0';
    if (primeiroDigito % 2 == 0) {
        return decrementa(n - 4);
    } else {
        return decrementa(n - 3);
    }
}

int main() {
    int n;
    cin >> n;
    cout << decrementa(n) << endl;
    return 0;
}
