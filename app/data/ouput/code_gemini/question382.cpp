/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int valor;
    double soma = 0.0;
    int contador = 0;

    while (std::cin >> valor && valor != 0) {
        soma += valor;
        contador++;
    }

    if (contador > 0) {
        double media = soma / contador;
        if (media < 110) {
            std::cout << "Glicose Normal\n";
        } else if (media >= 200) {
            std::cout << "Glicose Muito Alta\n";
        } else {
            std::cout << "Glicose Alterada\n";
        }
    }

    return 0;
}
