/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct Produto {
    std::string nome;
    double preco;
    int quantidade;
};

int main() {
    int N;
    std::cin >> N;
    std::vector<Produto> produtos(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> produtos[i].nome >> produtos[i].preco >> produtos[i].quantidade;
    }
    std::cin.ignore();
    std::string dia;
    std::getline(std::cin, dia);
    std::getline(std::cin, dia);
    double valor_pago;
    std::cin >> valor_pago;

    double valor_total = 0.0;
    std::cout << "=============" << std::endl;
    std::cout << "NF - 0123" << std::endl;
    std::cout << "Data - " << dia.substr(27, 5) << std::endl;  // Extraindo a data
    std::cout << "=============" << std::endl;

    for (const auto& p : produtos) {
        double subtotal = p.preco * p.quantidade;
        valor_total += subtotal;
        std::cout << p.quantidade << "x " << p.nome << " - R$" << std::fixed << std::setprecision(2) << subtotal << std::endl;
    }

    double troco = valor_pago - valor_total;
    std::cout << std::endl;
    std::cout << "Valor Total - R$" << std::fixed << std::setprecision(2) << valor_total << std::endl;
    std::cout << "Pago - R$" << std::fixed << std::setprecision(2) << valor_pago << std::endl;
    std::cout << "Troco - R$" << std::fixed << std::setprecision(2) << troco << std::endl;
    std::cout << "=============" << std::endl;

    return 0;
}
