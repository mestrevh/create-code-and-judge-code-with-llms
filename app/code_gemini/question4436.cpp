/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Produto {
    std::string nome;
    double valorUnitario;
    int quantidade;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Produto> produtos(n);
    double valorTotal = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> produtos[i].nome >> produtos[i].valorUnitario >> produtos[i].quantidade;
    }

    std::string data;
    double pago;
    
    std::string trash_word;
    for(int i = 0; i < 6; ++i) {
        std::cin >> trash_word;
    }
    std::cin >> data;

    std::string valorPagoStr;
    std::cin >> trash_word;
    std::cin >> valorPagoStr;
    pago = std::stod(valorPagoStr.substr(2));

    std::sort(produtos.begin(), produtos.end(), [](const Produto& a, const Produto& b) {
        return a.nome < b.nome;
    });
    
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "=============" << std::endl;
    std::cout << "NF - 0123" << std::endl;
    std::cout << "Data - " << data << std::endl;
    std::cout << "=============" << std::endl;

    for (const auto& produto : produtos) {
        double subtotal = produto.valorUnitario * produto.quantidade;
        valorTotal += subtotal;
        std::cout << produto.quantidade << "x " << produto.nome << " - R$" << subtotal << std::endl;
    }
    
    std::cout << std::endl;

    double troco = pago - valorTotal;
    std::cout << "Valor Total - R$" << valorTotal << std::endl;
    std::cout << "Pago - R$" << pago << std::endl;
    std::cout << "Troco - R$" << troco << std::endl;
    std::cout << "=============";

    return 0;
}
