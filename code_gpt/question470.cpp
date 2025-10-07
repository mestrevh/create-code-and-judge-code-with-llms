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
    int num, maxPrime = -1;
    while (true) {
        cin >> num;
        if (num == 404) break;
        if (isPrime(num) && num > maxPrime) {
            maxPrime = num;
        }
    }
    if (maxPrime == -1) {
        cout << "SEM PRIMOS" << endl;
    } else {
        cout << maxPrime << endl;
    }
    return 0;
}
