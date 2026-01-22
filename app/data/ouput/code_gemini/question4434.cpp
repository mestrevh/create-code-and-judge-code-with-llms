/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Produto {
    string nome;
    int quantidade;
    double preco;
    bool ocupado = false;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tamanho;
    cin >> tamanho;
    vector<vector<Produto>> estoque(tamanho, vector<Produto>(tamanho));

    string comando;
    while (cin >> comando) {
        if (comando == "EXIT") {
            cout << "Saindo...\n";
            break;
        }

        if (comando == "CREATE") {
            int linha, coluna;
            cin >> linha >> coluna;

            if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho && !estoque[linha][coluna].ocupado) {
                estoque[linha][coluna].ocupado = true;
                cin >> estoque[linha][coluna].nome >> estoque[linha][coluna].quantidade >> estoque[linha][coluna].preco;
                cout << "Produto adicionado no estoque!\n";
            } else {
                cout << "ERRO: espaço ja ocupado\n";
                string dummy_nome;
                int dummy_qtd;
                double dummy_preco;
                cin >> dummy_nome >> dummy_qtd >> dummy_preco;
            }
        } else if (comando == "READ") {
            string nome_busca;
            cin >> nome_busca;
            bool encontrado = false;
            for (int i = 0; i < tamanho; ++i) {
                for (int j = 0; j < tamanho; ++j) {
                    if (estoque[i][j].ocupado && estoque[i][j].nome == nome_busca) {
                        cout << fixed << setprecision(2);
                        cout << "LINHA: " << i << " COLUNA: " << j
                             << " QTD: " << estoque[i][j].quantidade
                             << " PRECO: " << estoque[i][j].preco << "\n";
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado) break;
            }
        } else if (comando == "UPDATE") {
            string nome_busca;
            cin >> nome_busca;
            int nova_qtd;
            double novo_preco;
            cin >> nova_qtd >> novo_preco;
            bool encontrado = false;
            for (int i = 0; i < tamanho; ++i) {
                for (int j = 0; j < tamanho; ++j) {
                    if (estoque[i][j].ocupado && estoque[i][j].nome == nome_busca) {
                        estoque[i][j].quantidade = nova_qtd;
                        estoque[i][j].preco = novo_preco;
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado) break;
            }
            if (encontrado) {
                cout << "Produto atualizado!\n";
            } else {
                cout << "Produto nao encontrado!\n";
            }
        } else if (comando == "DELETE") {
            string nome_busca;
            cin >> nome_busca;
            bool encontrado = false;
            for (int i = 0; i < tamanho; ++i) {
                for (int j = 0; j < tamanho; ++j) {
                    if (estoque[i][j].ocupado && estoque[i][j].nome == nome_busca) {
                        estoque[i][j].ocupado = false;
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado) break;
            }
            if (encontrado) {
                cout << "Produto removido!\n";
            } else {
                cout << "Produto nao encontrado!\n";
            }
        } else if (comando == "PRINT") {
            for (int i = 0; i < tamanho; ++i) {
                for (int j = 0; j < tamanho; ++j) {
                    if (estoque[i][j].ocupado) {
                        cout << fixed << setprecision(2);
                        cout << "LINHA: " << i << " COLUNA: " << j
                             << " NOME: " << estoque[i][j].nome
                             << " QTD: " << estoque[i][j].quantidade
                             << " PRECO: " << estoque[i][j].preco << "\n";
                    }
                }
            }
        }
    }

    return 0;
}
