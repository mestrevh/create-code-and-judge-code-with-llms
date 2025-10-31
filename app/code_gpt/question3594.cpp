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
    int a, b;
    cin >> a;
    cin >> b;

    while (b <= a) {
        cout << "Digite um valor maior que o primeiro!" << endl;
        cin >> b;
    }

    int sum = 0, count = 0;
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            sum += i;
            count++;
        }
    }

    if (count == 0) {
        cout << "Sem numeros primos no intervalo informado." << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}
