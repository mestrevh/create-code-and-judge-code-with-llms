/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void mmm(int lista[20], int *menor, int *maior, float *media) {
    *menor = lista[0];
    *maior = lista[0];
    int soma = 0;
    
    for(int i = 0; i < 20; ++i) {
        if(lista[i] < *menor) *menor = lista[i];
        if(lista[i] > *maior) *maior = lista[i];
        soma += lista[i];
    }
    
    *media = static_cast<float>(soma) / 20;
}

int main() {
    int lista[20];
    for(int i = 0; i < 20; ++i) {
        std::cin >> lista[i];
    }
    
    int menor, maior;
    float media;
    mmm(lista, &menor, &maior, &media);
    
    std::cout << maior << " " << menor << std::endl;
    std::cout << std::fixed << std::setprecision(1) << media << std::endl;
    
    return 0;
}
