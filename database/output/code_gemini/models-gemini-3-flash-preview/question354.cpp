/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void imprimir_pares(int n) {
    if (n < 0) {
        return;
    }
    if (n % 2 != 0) {
        imprimir_pares(n - 1);
    } else {
        imprimir_pares(n - 2);
        cout << n << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        imprimir_pares(n);
    }

    return 0;
}