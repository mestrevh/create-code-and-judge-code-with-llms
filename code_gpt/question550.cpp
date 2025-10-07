/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void gerarArrays(int *Y, int *X, int *Z, int seedY, int seedX, int seedZ, int A, int B, int C) {
    Y[0] = seedY;
    X[0] = seedX;
    Z[0] = seedZ;

    for (int i = 1; i < 10; i++) {
        Y[i] = (Y[i - 1] * A + B) % C;
        X[i] = (X[i - 1] * B + C) % A;
        Z[i] = (Z[i - 1] * C + A) % B;
    }
}

int maiorElemento(int *arr) {
    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int Modulo(int soma, int A, int B, int C) {
    return soma % ((A / B) + C);
}

int main() {
    int A, B, C, seedX, seedY, seedZ;
    cin >> A >> B >> C >> seedX >> seedY >> seedZ;

    int Y[10], X[10], Z[10];
    gerarArrays(Y, X, Z, seedY, seedX, seedZ, A, B, C);

    int MaxY = maiorElemento(Y);
    int MaxX = maiorElemento(X);
    int MaxZ = maiorElemento(Z);
    int soma = MaxX + MaxY + MaxZ;

    soma = Modulo(soma, A, B, C);
    cout << soma << endl;

    return 0;
}
