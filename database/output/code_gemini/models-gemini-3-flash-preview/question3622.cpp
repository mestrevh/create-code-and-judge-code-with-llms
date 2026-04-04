/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void calcular_media(int *A, int *B) {
    int valA = *A;
    int valB = *B;
    long long soma = (long long)valA + valB;
    int media = (int)(soma / 2);
    int resto = (int)(soma % 2);

    if (valA < valB) {
        *A = media;
        *B = resto;
    } else {
        *A = resto;
        *B = media;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    if (cin >> A >> B) {
        calcular_media(&A, &B);
        cout << "A = " << A << "\nB = " << B << endl;
    }

    return 0;
}