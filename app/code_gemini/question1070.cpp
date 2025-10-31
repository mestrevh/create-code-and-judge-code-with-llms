/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string dia, opcao, nome;
    double preco;

    std::cin >> dia >> preco >> opcao >> nome;

    double preco_final;

    if ((dia == "seg" || dia == "ter" || dia == "qua") && opcao == "ouro") {
        preco_final = preco / 2.0;
    } else if ((dia == "qui" || dia == "sex") && (preco >= 10.0 && preco <= 100.0)) {
        preco_final = preco / 3.0;
    } else if (dia == "sab" && opcao == "prata") {
        preco_final = preco * 3.0;
    } else {
        preco_final = preco * 2.0;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O preco do produto " << nome << " no dia " << dia << " eh " << preco_final << std::endl;

    return 0;
}
