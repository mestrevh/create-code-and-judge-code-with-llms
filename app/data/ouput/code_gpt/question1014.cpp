/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isAlmostPrime(int n) {
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (isPrime(i)) count++;
            if (i != n / i && isPrime(n / i)) count++;
        }
        if (count > 2) return false;
    }
    return count == 2;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        if (isPrime(N)) {
            cout << "Primo" << endl;
        } else if (isAlmostPrime(N)) {
            cout << "Quase primo" << endl;
        } else {
            cout << "Nem primo nem quase primo" << endl;
        }
    }
    return 0;
}
