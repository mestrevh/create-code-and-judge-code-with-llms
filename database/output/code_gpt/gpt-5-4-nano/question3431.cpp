/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> pedidos;
    string cmd;
    const string menu =
        "-----------------------------------\n"
        "Pizzaria 0.1 - menu de comandos\n"
        "-----------------------------------\n"
        "- ajuda: exibe o menu de ajuda\n"
        "- sair: encerra o programa\n"
        "- exibir: exibe a lista de pedidos\n"
        "- novo #pedido: adiciona o #pedido\n"
        "- cancela #pedido: remove o #pedido\n";

    while (cin >> cmd) {
        if (cmd == "ajuda") {
            cout << menu;
        } else if (cmd == "sair") {
            break;
        } else if (cmd == "exibir") {
            if (pedidos.empty()) {
                cout << "sem pedidos\n";
            } else {
                for (size_t i = 0; i < pedidos.size(); i++) {
                    if (i) cout << ' ';
                    cout << pedidos[i];
                }
                cout << "\n";
            }
        } else if (cmd == "novo") {
            string p;
            cin >> p;
            pedidos.push_back(p);
            cout << "pedido " << p << " adicionado\n";
        } else if (cmd == "cancela") {
            string p;
            cin >> p;
            auto it = find(pedidos.begin(), pedidos.end(), p);
            if (it == pedidos.end()) {
                cout << "pedido " << p << " inexistente\n";
            } else {
                pedidos.erase(it);
                cout << "pedido " << p << " removido\n";
            }
        }
    }

    return 0;
}