/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string resultados;
    int pedroEscalado, yuriEscalado, golsFlamengo, golsCorinthians;
    double mediaGolsFlamengo, mediaGolsCorinthians;

    std::cin >> resultados >> pedroEscalado >> yuriEscalado >> golsFlamengo >> golsCorinthians >> mediaGolsFlamengo >> mediaGolsCorinthians;

    int pontosFlamengo = 0, pontosCorinthians = 0;

    int vitoriasFlamengo = std::count(resultados.begin(), resultados.end(), 'f');
    int vitoriasCorinthians = std::count(resultados.begin(), resultados.end(), 'c');

    if (vitoriasFlamengo > vitoriasCorinthians) pontosFlamengo += 40;
    else if (vitoriasCorinthians > vitoriasFlamengo) pontosCorinthians += 40;

    if (pedroEscalado) pontosFlamengo += 20;
    if (yuriEscalado) pontosCorinthians += 20;

    if (golsFlamengo > golsCorinthians) pontosFlamengo += 15;
    else if (golsCorinthians > golsFlamengo) pontosCorinthians += 15;

    if (mediaGolsFlamengo >= 2 && mediaGolsCorinthians >= 2) {
        if (mediaGolsFlamengo > mediaGolsCorinthians) pontosFlamengo += 10;
        else if (mediaGolsCorinthians > mediaGolsFlamengo) pontosCorinthians += 10;
        else { pontosFlamengo += 10; pontosCorinthians += 10; }
    } else {
        if (mediaGolsFlamengo >= 2) pontosFlamengo += 10;
        if (mediaGolsCorinthians >= 2) pontosCorinthians += 10;
    }

    if (pontosFlamengo > pontosCorinthians) {
        std::cout << "Luiza tem mais chances de comer o brownie\nPontos:" << pontosFlamengo << std::endl;
    } else {
        std::cout << "Pedro tem mais chances de comer o brownie\nPontos:" << pontosCorinthians << std::endl;
    }

    return 0;
}
