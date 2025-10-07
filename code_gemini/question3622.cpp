/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void calcular_media(int *ptrA, int *ptrB) {
    int valA = *ptrA;
    int valB = *ptrB;

    int soma = valA + valB;
    int media = soma / 2;
    int resto = soma % 2;

    if (valA < valB) {
        *ptrA = media;
        *ptrB = resto;
    } else {
        *ptrB = media;
        *ptrA = resto;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B;
    std::cin >> A >> B;

    calcular_media(&A, &B);

    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;

    return 0;
}
