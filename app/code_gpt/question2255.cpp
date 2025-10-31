/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int contaDigitos(unsigned long long n) {
    int count = 0;
    do {
        count++;
        n /= 10;
    } while (n > 0);
    return count;
}

int main() {
    unsigned long long n;
    cin >> n;
    cout << contaDigitos(n) << endl;
    return 0;
}
