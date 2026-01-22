/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int primeCount = 0;
    primeCount += isPrime(a) ? 1 : 0;
    primeCount += isPrime(b) ? 1 : 0;
    primeCount += isPrime(c) ? 1 : 0;

    if (primeCount == 0) {
        cout << "Seguro" << endl;
    } else if (primeCount == 1) {
        cout << "Possível Risco" << endl;
    } else {
        cout << "Perigo" << endl;
    }

    return 0;
}
