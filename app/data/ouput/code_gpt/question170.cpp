/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (isPrime(a) && isPrime(b) && isPrime(c) && isPrime(d)) {
        cout << a * b * c * d << endl;
    } else {
        cout << "SEM PRODUTO" << endl;
    }

    return 0;
}
