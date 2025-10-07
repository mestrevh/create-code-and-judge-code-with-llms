/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int cor;
    std::cin >> cor;
    std::cin.ignore();

    std::string frase;
    std::getline(std::cin, frase);

    int num_letras = frase.length();

    double preco1;
    if (cor == 1) {
        preco1 = 2.0;
    } else {
        preco1 = 4.0;
    }

    if (num_letras >= 1 && num_letras <= 10) {
        preco1 += num_letras * 0.75;
    } else if (num_letras >= 11 && num_letras <= 30) {
        preco1 += num_letras * 0.45;
    } else if (num_letras >= 31 && num_letras <= 200) {
        preco1 += num_letras * 0.20;
    }

    double preco2;
    if (cor == 1) {
        preco2 = 6.0;
    } else {
        preco2 = 9.0;
    }

    if (num_letras >= 1 && num_letras <= 10) {
        preco2 += num_letras * 0.25;
    } else if (num_letras >= 11 && num_letras <= 30) {
        preco2 += num_letras * 0.15;
    } else if (num_letras >= 31 && num_letras <= 200) {
        preco2 += num_letras * 0.10;
    }

    std::cout << std::fixed << std::setprecision(2);

    if (preco1 <= preco2) {
        std::cout << "A grafica 1 eh a mais em conta" << std::endl;
        std::cout << "O preco sera: $" << preco1 << std::endl;
    } else {
        std::cout << "A grafica 2 eh a mais em conta" << std::endl;
        std::cout << "O preco sera: $" << preco2 << std::endl;
    }

    return 0;
}
