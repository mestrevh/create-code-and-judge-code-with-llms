/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Produto {
    string nome;
    double preco;
};

struct Mercado {
    int distancia;
    vector<Produto> produtos;
};

struct ListaCompras {
    vector<string> itens;
};

int main() {
    int n;
    cin >> n;
    vector<Mercado> mercados(n);

    for (int i = 0; i < n; i++) {
        cin >> mercados[i].distancia;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            Produto p;
            cin >> ws;
            getline(cin, p.nome, '-');
            cin >> p.preco;
            mercados[i].produtos.push_back(p);
        }
    }

    ListaCompras lista;
    int tamanhoLista;
    cin >> tamanhoLista;
    lista.itens.resize(tamanhoLista);
    for (int i = 0; i < tamanhoLista; i++) {
        cin >> ws;
        getline(cin, lista.itens[i]);
    }

    int melhorMercado = -1;
    int maxItens = 0;

    for (int i = 0; i < n; i++) {
        int contagem = 0;
        for (const string& item : lista.itens) {
            for (const Produto& p : mercados[i].produtos) {
                if (p.nome == item) {
                    contagem++;
                    break;
                }
            }
        }
        if (contagem > maxItens || (contagem == maxItens && (melhorMercado == -1 || mercados[i].distancia < mercados[melhorMercado].distancia))) {
            melhorMercado = i;
            maxItens = contagem;
        }
    }

    if (melhorMercado != -1) {
        cout << "Mercado: " << melhorMercado + 1 << endl;
        double total = 0.0;
        for (const string& item : lista.itens) {
            for (const Produto& p : mercados[melhorMercado].produtos) {
                if (p.nome == item) {
                    cout << item << " " << fixed << setprecision(2) << p.preco << endl;
                    total += p.preco;
                    break;
                }
            }
        }
        cout << fixed << setprecision(2) << total << endl;
    }

    return 0;
}
