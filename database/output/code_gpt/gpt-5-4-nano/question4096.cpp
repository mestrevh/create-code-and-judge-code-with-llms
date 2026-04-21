/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Produto {
    int codigo;
    string descricao;
    double preco;
};

void cadastraProduto(Produto *p) {
    cin >> p->codigo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p->descricao);
    cin >> p->preco;
}

double retornaPreco(Produto p[], int qntdProdutosCadastrados, int codigo) {
    for (int i = 0; i < qntdProdutosCadastrados; i++) {
        if (p[i].codigo == codigo) return p[i].preco;
    }
    return -1.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Digite a quantidade de produtos a serem cadastrados: ";
    if (!(cin >> n)) return 0;

    vector<Produto> produtos(n);
    for (int i = 0; i < n; i++) {
        cadastraProduto(&produtos[i]);
    }

    cout << "Digite o codigo, descricao e preco dos " << n << " produtos: ";
    cin.clear();

    cout << "Digite o(s) codigo(s) e a quantidade do(s) produto(s) desejado(s):\n";

    long long totalItens = 0;
    double totalPagar = 0.0;

    while (true) {
        int codigo;
        if (!(cin >> codigo)) break;
        if (codigo == 0) break;
        long long qtd;
        cin >> qtd;
        if (qtd < 0) continue;

        double preco = retornaPreco(produtos.data(), n, codigo);
        if (preco < 0) continue;

        totalItens += qtd;
        totalPagar += (double)qtd * preco;
    }

    cout << "Quantidade de itens do seu pedido: " << totalItens << "\n";
    cout << fixed << setprecision(2);
    cout << "Total a pagar: " << totalPagar << "\n";
    return 0;
}