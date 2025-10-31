/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void calcular_media(int *A, int *B) {
    if (*A > *B) {
        swap(A, B);
    }
    *A = (*A + *B) / 2;
    *B = *B % (*A == 0 ? 1 : *A);
}

int main() {
    int A, B;
    cin >> A >> B;
    calcular_media(&A, &B);
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    return 0;
}
