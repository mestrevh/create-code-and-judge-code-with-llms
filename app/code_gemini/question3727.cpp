/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double CalculaMedia(double n1, double n2, double n3, double n4, double n5) {
    return (n1 + n2 + n3 + n4 + n5) / 5.0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int faltas;
    double nota1, nota2, nota3, nota4, nota5;

    std::cin >> faltas;
    std::cin >> nota1 >> nota2 >> nota3 >> nota4 >> nota5;

    double media = CalculaMedia(nota1, nota2, nota3, nota4, nota5);

    if (faltas <= 5 && media >= 7.0) {
        std::cout << "APROVADO" << std::endl;
    } else {
        std::cout << "REPROVADO" << std::endl;
    }

    return 0;
}
