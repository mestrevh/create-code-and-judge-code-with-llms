/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int ContaDigitosPares(int n) {
    if (n == 0) return 0;
    int digito = n % 10;
    return (digito % 2 == 0) + ContaDigitosPares(n / 10);
}

int main() {
    int n;
    cin >> n;
    cout << ContaDigitosPares(n) << endl;
    return 0;
}
