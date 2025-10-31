/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
    int quantidade;

    bool operator<(const Produto& p) const {
        return nome < p.nome;
    }
};

int main() {
    int N;
    cin >> N;
    vector<Produto> estoque(N);
    
    for (int i = 0; i < N; i++) {
        cin >> estoque[i].codigo >> estoque[i].nome >> estoque[i].preco >> estoque[i].quantidade;
    }

    int M;
    cin >> M;
    while (M--) {
        string operacao;
        cin >> operacao;

        if (operacao == "Venda") {
            int X;
            cin >> X;
            vector<pair<int, int>> compras(X);
            float valorRecebido;

            for (int i = 0; i < X; i++) {
                cin >> compras[i].first >> compras[i].second;
            }
            cin >> valorRecebido;

            float total = 0;
            bool possivel = true;

            for (const auto& compra : compras) {
                int codigo = compra.first;
                int qtd = compra.second;
                for (auto& produto : estoque) {
                    if (produto.codigo == codigo) {
                        if (produto.quantidade >= qtd) {
                            total += produto.preco * qtd;
                            produto.quantidade -= qtd;
                        } else {
                            possivel = false;
                        }
                    }
                }
            }

            if (possivel && total <= valorRecebido) {
                cout << fixed << setprecision(2);
                for (const auto& compra : compras) {
                    int codigo = compra.first;
                    for (const auto& produto : estoque) {
                        if (produto.codigo == codigo) {
                            cout << produto.nome << " - R$" << produto.preco << " - " << compra.second << " - R$" << produto.preco * compra.second << endl;
                        }
                    }
                }
                cout << "Total: R$" << total << endl;
                cout << "Pago: R$" << valorRecebido << endl;
                cout << "Troco: R$" << valorRecebido - total << endl;
            } else {
                cout << "Nao foi possivel realizar a venda" << endl;
                for (const auto& compra : compras) {
                    int codigo = compra.first;
                    for (auto& produto : estoque) {
                        if (produto.codigo == codigo) {
                            produto.quantidade += compra.second; 
                        }
                    }
                }
            }
        } else if (operacao == "Estoque") {
            sort(estoque.begin(), estoque.end());
            cout << "Estoque atual:" << endl;
            for (int i = 0; i < N; i++) {
                cout << i + 1 << ". " << estoque[i].codigo << " - " << estoque[i].nome << " - " << estoque[i].quantidade << endl;
            }
        }
    }
    return 0;
}
