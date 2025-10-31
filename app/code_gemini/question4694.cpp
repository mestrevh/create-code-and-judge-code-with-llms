/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <utility>

struct Produto {
    int codigo;
    std::string nome;
    float preco;
    int quantidade;
};

bool compararPorNome(const Produto& a, const Produto& b) {
    return a.nome < b.nome;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << std::fixed << std::setprecision(2);

    int n;
    std::cin >> n;

    std::vector<Produto> estoque(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> estoque[i].codigo;
        std::cin.ignore();
        std::cin >> estoque[i].nome >> estoque[i].preco >> estoque[i].quantidade;
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        std::string operacao;
        std::cin >> operacao;

        if (operacao == "Venda") {
            int x;
            std::cin >> x;

            std::vector<std::pair<int, int>> carrinho(x);
            for (int j = 0; j < x; ++j) {
                std::cin >> carrinho[j].first >> carrinho[j].second;
            }

            float valor_pago;
            std::cin >> valor_pago;

            bool possivel = true;
            std::vector<std::pair<int, int>> itens_compra;

            for (const auto& item_carrinho : carrinho) {
                int cod_prod = item_carrinho.first;
                int qtd_compra = item_carrinho.second;
                int index_estoque = -1;

                for (int k = 0; k < estoque.size(); ++k) {
                    if (estoque[k].codigo == cod_prod) {
                        index_estoque = k;
                        break;
                    }
                }

                if (index_estoque == -1 || estoque[index_estoque].quantidade < qtd_compra) {
                    possivel = false;
                    break;
                }
                itens_compra.push_back({index_estoque, qtd_compra});
            }

            if (!possivel) {
                std::cout << "Nao foi possivel realizar a venda\n";
            } else {
                float total = 0.0f;
                
                std::vector<std::tuple<std::string, float, int, float>> recibo;

                for (const auto& item : itens_compra) {
                    int idx = item.first;
                    int qtd = item.second;
                    float subtotal = estoque[idx].preco * qtd;
                    total += subtotal;
                    recibo.emplace_back(estoque[idx].nome, estoque[idx].preco, qtd, subtotal);
                }
                
                for(const auto& linha : recibo){
                    std::cout << std::get<0>(linha) << " - R$" << std::get<1>(linha)
                              << " - " << std::get<2>(linha) << " - R$" << std::get<3>(linha) << "\n";
                }

                std::cout << "Total: R$" << total << "\n";
                std::cout << "Pago: R$" << valor_pago << "\n";
                std::cout << "Troco: R$" << valor_pago - total << "\n";

                for (const auto& item : itens_compra) {
                    int idx = item.first;
                    int qtd = item.second;
                    estoque[idx].quantidade -= qtd;
                }
            }

        } else if (operacao == "Estoque") {
            std::vector<Produto> estoque_ordenado = estoque;
            std::sort(estoque_ordenado.begin(), estoque_ordenado.end(), compararPorNome);

            std::cout << "Estoque atual:\n";
            for (int j = 0; j < estoque_ordenado.size(); ++j) {
                std::cout << j + 1 << ". " << estoque_ordenado[j].codigo << " - "
                          << estoque_ordenado[j].nome << " - " << estoque_ordenado[j].quantidade << "\n";
            }
        }
    }

    return 0;
}
