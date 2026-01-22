/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long fatorial(int n) {
    return (n <= 1) ? 1 : n * fatorial(n - 1);
}

int main() {
    int num, soma = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> num;
        if (num % 3 == 0) {
            soma += fatorial(num);
        }
    }
    cout << soma << endl;
    return 0;
}
