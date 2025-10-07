/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    char bairro;
    double renda, consumo;

    std::cin >> bairro >> renda >> consumo;

    if (renda < 0 || consumo < 0) {
        std::cout << "Renda e consumo nao podem ser negativos." << std::endl;
        return 0;
    }

    double desconto = 0.0;

    switch (bairro) {
        case 'S':
            if (renda >= 50 && renda <= 500) {
                desconto = 50;
            } else if (renda > 500 && renda <= 1000) {
                desconto = 25;
            }
            break;
        case 'I':
            if (renda >= 240 && renda <= 1000) {
                desconto = 240;
            } else if (renda > 1000 && renda <= 5000) {
                desconto = 120;
            }
            break;
        case 'T':
            if (renda >= 5000 && renda <= 10000) {
                desconto = 720;
            } else if (renda > 10000 && renda <= 20000) {
                desconto = 360;
            }
            break;
        default:
            std::cout << "Bairro invalido." << std::endl;
            return 0;
    }

    double valorFinal = consumo - desconto;
    if (valorFinal < 0) {
        valorFinal = 0;
    }
    std::cout << valorFinal << std::endl;

    return 0;
}
