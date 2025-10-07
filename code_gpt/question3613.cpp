/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Venda {
    string nome_cliente;
    int quantidade;
    float valor_total;
    string cidade_destino;
};

int main() {
    Venda vendas[10];
    int count = 0;
    float total_valor = 0;
    int total_quantidade = 0;
    Venda maior_venda;

    while (count < 10) {
        string nome;
        getline(cin, nome);
        if (nome == "encerrar") break;

        vendas[count].nome_cliente = nome;
        cin >> vendas[count].quantidade;
        cin >> vendas[count].valor_total;
        cin.ignore();
        getline(cin, vendas[count].cidade_destino);

        total_quantidade += vendas[count].quantidade;
        total_valor += vendas[count].valor_total;

        if (count == 0 || vendas[count].valor_total > maior_venda.valor_total) {
            maior_venda = vendas[count];
        }
        count++;
    }

    cout << fixed << setprecision(2);
    cout << "Quantidade vendida: " << total_quantidade << endl;
    cout << "Valor arrecadado: " << total_valor << endl;
    cout << maior_venda.nome_cliente << endl;
    cout << maior_venda.cidade_destino << endl;

    return 0;
}
