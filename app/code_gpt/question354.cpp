/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void imprimePares(int n, int current = 0) {
    if (current <= n) {
        cout << current << endl;
        imprimePares(n, current + 2);
    }
}

int main() {
    int N;
    cin >> N;
    if (N % 2 != 0) N--; // Garantir que N seja par
    imprimePares(N);
    return 0;
}
