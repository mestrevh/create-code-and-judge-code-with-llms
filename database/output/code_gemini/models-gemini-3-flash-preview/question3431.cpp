/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    vector<string> orders;

    while (cin >> cmd) {
        if (cmd == "sair") {
            break;
        } else if (cmd == "ajuda") {
            cout << "-----------------------------------" << "\n";
            cout << "Pizzaria 0.1 - menu de comandos" << "\n";
            cout << "-----------------------------------" << "\n";
            cout << "- ajuda: exibe o menu de ajuda" << "\n";
            cout << "- sair: encerra o programa" << "\n";
            cout << "- exibir: exibe a lista de pedidos" << "\n";
            cout << "- novo #pedido: adiciona o #pedido" << "\n";
            cout << "- cancela #pedido: remove o #pedido" << "\n";
            cout << "-----------------------------------" << "\n";
        } else if (cmd == "exibir") {
            if (orders.empty()) {
                cout << "sem pedidos" << "\n";
            } else {
                for (size_t i = 0; i < orders.size(); ++i) {
                    cout << orders[i] << (i + 1 == orders.size() ? "" : " ");
                }
                cout << "\n";
            }
        } else if (cmd == "novo") {
            string id;
            cin >> id;
            orders.push_back(id);
            cout << "pedido " << id << " adicionado" << "\n";
        } else if (cmd == "cancela") {
            string id;
            cin >> id;
            auto it = find(orders.begin(), orders.end(), id);
            if (it != orders.end()) {
                orders.erase(it);
                cout << "pedido " << id << " removido" << "\n";
            } else {
                cout << "pedido " << id << " inexistente" << "\n";
            }
        }
    }

    return 0;
}