/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct produto {
    int codigo;
    string descricao;
    float preco;
};

void cadastraProduto(struct produto *p) {
    if (!(cin >> p->codigo)) return;
    cin.ignore(1000, '\n');
    getline(cin, p->descricao);
    cin >> p->preco;
}

float retornaPreco(struct produto p[], int qntdProdutosCadastrados, int codigo) {
    for (int i = 0; i < qntdProdutosCadastrados; i++) {
        if (p[i].codigo == codigo) {
            return p[i].preco;
        }
    }
    return -1.0f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Digite a quantidade de produtos a serem cadastrados:" << endl;
    if (!(cin >> n)) return 0;

    vector<produto> produtos(n);
    cout << "Digite o codigo, descricao e preco dos " << n << " produtos:" << endl;
    for (int i = 0; i < n; i++) {
        cadastraProduto(&produtos[i]);
    }

    cout << "Digite o(s) codigo(s) e a quantidade do(s) produto(s) desejado(s):" << endl;

    int codigo;
    int totalQuantidade = 0;
    double totalPagar = 0.0;

    while (cin >> codigo && codigo != 0) {
        int quantidade;
        if (!(cin >> quantidade)) break;

        if (quantidade < 0) {
            continue;
        }

        float preco = retornaPreco(produtos.data(), n, codigo);
        if (preco != -1.0f) {
            totalQuantidade += quantidade;
            totalPagar += (double)quantidade * (double)preco;
        }
    }

    cout << "Quantidade de itens do seu pedido: " << totalQuantidade << endl;
    cout << "Total a pagar: " << fixed << setprecision(2) << totalPagar << endl;

    return 0;
}