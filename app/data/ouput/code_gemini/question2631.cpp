/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;

    std::cout << "Digite o valor de Alice:" << std::endl;
    std::cin >> a;
    std::cout << "Digite o valor de Beto:" << std::endl;
    std::cin >> b;
    std::cout << "Digite o valor de Clara:" << std::endl;
    std::cin >> c;

    if ((a != 0 && a != 1) || (b != 0 && b != 1) || (c != 0 && c != 1)) {
        std::cout << "Algum valor digitado e diferente de 0 ou 1." << std::endl;
    } else {
        if (a != b && a != c) {
            std::cout << "O vencedor e Alice." << std::endl;
        } else if (b != a && b != c) {
            std::cout << "O vencedor e Beto." << std::endl;
        } else if (c != a && c != b) {
            std::cout << "O vencedor e Clara." << std::endl;
        } else {
            std::cout << "Nao houve vencedor." << std::endl;
        }
    }

    return 0;
}
