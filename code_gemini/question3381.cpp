/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int idade;
    std::cin >> idade;
    if (idade <= 2) {
        std::cout << "O individuo eh um Bebe Jovem Menor de Idade.\n";
    } else if (idade <= 12) {
        std::cout << "O individuo eh uma Crianca Jovem Menor de Idade.\n";
    } else if (idade < 18) {
        std::cout << "O individuo eh um Adolescente Jovem Menor de Idade.\n";
    } else if (idade <= 19) {
        std::cout << "O individuo eh um Jovem Maior de Idade.\n";
    } else if (idade <= 45) {
        std::cout << "O individuo eh um Adulto Maior de Idade.\n";
    } else if (idade < 60) {
        std::cout << "O individuo eh um Adulto de Meia Idade Maior de Idade.\n";
    } else if (idade <= 75) {
        std::cout << "O individuo eh um Idoso Maior de Idade.\n";
    } else if (idade <= 90) {
        std::cout << "O individuo eh um Idoso Ansiao Maior de Idade.\n";
    } else {
        std::cout << "O individuo eh um Idoso na Velhice Extrema Maior de Idade.\n";
    }
    return 0;
}
