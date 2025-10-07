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
    int number;
    while (true) {
        cin >> number;
        if (number == -1) break;
        cout << (isPrime(number) ? 1 : 0) << endl;
    }
    return 0;
}
