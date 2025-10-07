/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void mmm(int lista[20], int *menor, int *maior, float *media) {
    *maior = lista[0];
    *menor = lista[0];

    for (int i = 1; i < 20; ++i) {
        if (lista[i] > *maior) {
            *maior = lista[i];
        }
        if (lista[i] < *menor) {
            *menor = lista[i];
        }
    }

    *media = (float)(*maior + *menor) / 2.0f;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int lista[20];
    int maior_val, menor_val;
    float media_val;

    for (int i = 0; i < 20; ++i) {
        std::cin >> lista[i];
    }

    mmm(lista, &menor_val, &maior_val, &media_val);

    std::cout << maior_val << " " << menor_val << std::endl;
    std::cout << std::fixed << std::setprecision(1) << media_val << std::endl;

    return 0;
}
