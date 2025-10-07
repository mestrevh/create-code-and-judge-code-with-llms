/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct produto {
    int codigo;
    std::string descricao;
    float preco;
};

void cadastraProduto(struct produto *p) {
    std::cin >> p->codigo;
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, p->descricao);
    std::cin >> p->preco;
}

float retornaPreco(struct produto p[], int qntdProdutosCadastrados, int codigo) {
    for (int i = 0; i < qntdProdutosCadastrados; ++i) {
        if (p[i].codigo == codigo) {
            return p[i].preco;
        }
    }
    return -1.0f;
}

int main() {
    int n;
    std::cout << "Digite a quantidade de produtos a serem cadastrados:\n";
    std::cin >> n;

    if (n < 0) {
        n = 0;
    }

    std::vector<produto> cardapio(n);

    if (n > 0) {
        std::cout << "Digite o codigo, descricao e preco dos " << n << " produtos:\n";
        for (int i = 0; i < n; ++i) {
            cadastraProduto(&cardapio[i]);
        }
    }

    std::cout << "Digite o(s) codigo(s) e a quantidade do(s) produto(s) desejado(s):\n";

    int total_itens = 0;
    double total_pagar = 0.0;
    int codigo_pedido;
    int quantidade_pedido;

    while (std::cin >> codigo_pedido && codigo_pedido != 0) {
        std::cin >> quantidade_pedido;

        if (quantidade_pedido > 0) {
            float preco_produto = -1.0f;
            if (n > 0) {
               preco_produto = retornaPreco(cardapio.data(), n, codigo_pedido);
            }
            
            if (preco_produto >= 0) {
                total_itens += quantidade_pedido;
                total_pagar += quantidade_pedido * preco_produto;
            }
        }
    }

    std::cout << "Quantidade de itens do seu pedido: " << total_itens << "\n";
    std::cout << "Total a pagar: " << std::fixed << std::setprecision(2) << total_pagar << "\n";

    return 0;
}
