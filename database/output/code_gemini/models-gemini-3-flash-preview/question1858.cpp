/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int obterMenor(int* arr) {
    int menor = arr[0];
    for (int i = 1; i < 6; ++i) {
        if (arr[i] < menor) {
            menor = arr[i];
        }
    }
    return menor;
}

int obterMaior(int* arr) {
    int maior = arr[0];
    for (int i = 1; i < 6; ++i) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
    }
    return maior;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int valores[6];
    for (int i = 0; i < 6; ++i) {
        if (!(std::cin >> valores[i])) break;
    }

    std::cout << obterMenor(valores) << "\n";
    std::cout << obterMaior(valores) << "\n";

    return 0;
}