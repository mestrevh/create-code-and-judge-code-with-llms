/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int encontrarMenor(int* arr) {
    int menor = arr[0];
    for (int i = 1; i < 6; ++i) {
        if (arr[i] < menor) {
            menor = arr[i];
        }
    }
    return menor;
}

int encontrarMaior(int* arr) {
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
        std::cin >> valores[i];
    }

    int menor_valor = encontrarMenor(valores);
    int maior_valor = encontrarMaior(valores);

    std::cout << menor_valor << std::endl;
    std::cout << maior_valor << std::endl;

    return 0;
}
