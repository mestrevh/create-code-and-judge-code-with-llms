/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < 7; i++) {
        int quantidade = X / notas[i];
        X %= notas[i];
        cout << quantidade << " nota(s) de R$ " << notas[i] << ",00" << endl;
    }
    return 0;
}
