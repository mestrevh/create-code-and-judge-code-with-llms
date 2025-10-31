/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> estoque;
    int codigo, quantidade;

    while (true) {
        cin >> codigo;
        if (codigo == 9999) break;
        cin >> quantidade;
        estoque[codigo] += quantidade;
    }

    while (true) {
        int cliente, pedido_codigo, pedido_quantidade;
        cin >> cliente;
        if (cliente == 9999) break;
        cin >> pedido_codigo >> pedido_quantidade;

        if (estoque[pedido_codigo] >= pedido_quantidade) {
            estoque[pedido_codigo] -= pedido_quantidade;
            cout << "OK" << endl;
        } else {
            cout << "ESTOQUE INSUFICIENTE" << endl;
        }
    }

    for (const auto& item : estoque) {
        cout << item.first << ' ' << item.second << endl;
    }

    return 0;
}
