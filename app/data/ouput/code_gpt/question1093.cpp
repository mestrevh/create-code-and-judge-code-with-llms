/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int idade, menor_idade = numeric_limits<int>::max(), total_vendas = 0;
    float valor_compra, maior_compra = numeric_limits<float>::lowest(), total_venda_vista = 0, total_venda_cartao = 0;
    char tipo_pagamento, continuar;
    float media_vista = 0;
    int cont_vista = 0;

    do {
        cin >> idade >> valor_compra >> tipo_pagamento;
        total_vendas++;

        if (tipo_pagamento == 'V') {
            total_venda_vista += valor_compra;
            cont_vista++;
        } else {
            total_venda_cartao += valor_compra;
        }

        if (idade < menor_idade) menor_idade = idade;
        if (valor_compra > maior_compra) maior_compra = valor_compra;

        cin >> continuar;

    } while (continuar == 'S');

    media_vista = (cont_vista > 0) ? total_venda_vista / cont_vista : 0;

    cout << total_vendas << endl;
    cout << fixed << setprecision(2) << total_venda_vista << endl;
    cout << fixed << setprecision(2) << total_venda_cartao << endl;
    cout << menor_idade << endl;
    cout << fixed << setprecision(2) << maior_compra << endl;
    cout << fixed << setprecision(2) << media_vista << endl;

    return 0;
}
