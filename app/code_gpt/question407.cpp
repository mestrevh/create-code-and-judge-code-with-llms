/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int ciclo(int n) {
    int tamanho = 1;
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        tamanho++;
    }
    return tamanho;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int max_ciclo = 0;
        for (int k = min(i, j); k <= max(i, j); k++) {
            max_ciclo = max(max_ciclo, ciclo(k));
        }
        cout << i << " " << j << " " << max_ciclo << endl;
    }
    return 0;
}
