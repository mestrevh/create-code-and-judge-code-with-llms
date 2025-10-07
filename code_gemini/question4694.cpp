/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Produto {
    int codigo;
    string nome;
    double preco;
    int quantidade;
};

bool compareProdutos(const Produto& a, const Produto& b) {
    return a.nome < b.nome;
}

int main() {
    int n;
    cin >> n;

    vector<Produto> produtos(n);
    for (int i = 0; i < n; ++i) {
        cin >> produtos[i].codigo >> produtos[i].nome >> produtos[i].preco >> produtos[i].quantidade;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        string operacao;
        cin >> operacao;

        if (operacao == "Venda") {
            int x;
            cin >> x;

            vector<pair<int, int>> compra(x);
            for (int j = 0; j < x; ++j) {
                cin >> compra[j].first >> compra[j].second;
            }

            double pago;
            cin >> pago;

            double total = 0;
            bool possivel = true;
            vector<pair<string, pair<double, int>>> nota;

            for (int j = 0; j < x; ++j) {
                int codigo = compra[j].first;
                int quantidade = compra[j].second;

                int index = -1;
                for (int k = 0; k < n; ++k) {
                    if (produtos[k].codigo == codigo) {
                        index = k;
                        break;
                    }
                }

                if (index != -1 && produtos[index].quantidade >= quantidade) {
                    total += produtos[index].preco * quantidade;
                    nota.push_back({produtos[index].nome, {produtos[index].preco, quantidade}});
                } else {
                    possivel = false;
                    break;
                }
            }

            if (possivel) {
                for (const auto& item : nota) {
                    cout << item.first << " - R$" << fixed << setprecision(2) << item.second.first << " - " << item.second.second << " - R$" << fixed << setprecision(2) << item.second.first * item.second.second << endl;
                }
                cout << "Total: R$" << fixed << setprecision(2) << total << endl;
                cout << "Pago: R$" << fixed << setprecision(2) << pago << endl;
                cout << "Troco: R$" << fixed << setprecision(2) << pago - total << endl;

                for (int j = 0; j < x; ++j) {
                    int codigo = compra[j].first;
                    int quantidade = compra[j].second;
                    for (int k = 0; k < n; ++k) {
                        if (produtos[k].codigo == codigo) {
                            produtos[k].quantidade -= quantidade;
                            break;
                        }
                    }
                }
            } else {
                cout << "Nao foi possivel realizar a venda" << endl;
            }
        } else if (operacao == "Estoque") {
            sort(produtos.begin(), produtos.end(), compareProdutos);
            cout << "Estoque atual:" << endl;
            for (int j = 0; j < n; ++j) {
                cout << j + 1 << ". " << produtos[j].codigo << " - " << produtos[j].nome << " - " << produtos[j].quantidade << endl;
            }
        }
    }

    return 0;
}
