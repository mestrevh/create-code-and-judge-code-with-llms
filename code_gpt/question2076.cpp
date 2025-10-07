/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int contarDivisores(int n) {
    int cont = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) cont++;
    }
    return cont;
}

int main() {
    int A, B;
    cin >> A >> B;
    
    int maxDivisores = 0, numero = A;
    
    for (int i = A; i <= B; i++) {
        int divs = contarDivisores(i);
        if (divs > maxDivisores) {
            maxDivisores = divs;
            numero = i;
        }
    }
    
    cout << numero << " " << maxDivisores << endl;
    return 0;
}
