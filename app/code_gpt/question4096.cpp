/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct produto {
    int codigo;
    string descricao;
    float preco;
};

void cadastraProduto(produto *p) {
    cin >> p->codigo;
    cin.ignore(); // Para ignorar o newline após o código
    getline(cin, p->descricao);
    cin >> p->preco;
}

float retornaPreco(produto p[], int qntdProdutosCadastrados, int codigo) {
    for (int i = 0; i < qntdProdutosCadastrados; i++) {
        if (p[i].codigo == codigo) {
            return p[i].preco;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Digite a quantidade de produtos a serem cadastrados:" << endl;
    cin >> n;

    produto *produtos = new produto[n];
    cout << "Digite o codigo, descricao e preco dos " << n << " produtos:" << endl;
    for (int i = 0; i < n; i++) {
        cadastraProduto(&produtos[i]);
    }

    int codigo, quantidade;
    int totalItems = 0;
    float totalPrice = 0.0;

    cout << "Digite o(s) codigo(s) e a quantidade do(s) produto(s) desejado(s):" << endl;
    while (true) {
        cin >> codigo;
        if (codigo == 0) break;
        cin >> quantidade;
        if (quantidade < 0) continue;

        float preco = retornaPreco(produtos, n, codigo);
        if (preco >= 0) {
            totalItems += quantidade;
            totalPrice += preco * quantidade;
        }
    }

    cout << "Quantidade de itens do seu pedido: " << totalItems << endl;
    cout << "Total a pagar: " << fixed << setprecision(2) << totalPrice << endl;

    delete[] produtos;
    return 0;
}
