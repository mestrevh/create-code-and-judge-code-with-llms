/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void exibirMenu() {
    cout << "-----------------------------------\n"
         << "Pizzaria 0.1 - menu de comandos\n"
         << "-----------------------------------\n"
         << "- ajuda: exibe o menu de ajuda\n"
         << "- sair: encerra o programa\n"
         << "- exibir: exibe a lista de pedidos\n"
         << "- novo #pedido: adiciona o #pedido\n"
         << "- cancela #pedido: remove o #pedido\n"
         << "-----------------------------------\n";
}

int main() {
    vector<string> pedidos;
    string comando;
    
    while (true) {
        getline(cin, comando);
        istringstream iss(comando);
        string acao;
        iss >> acao;

        if (acao == "sair") {
            break;
        } else if (acao == "ajuda") {
            exibirMenu();
        } else if (acao == "exibir") {
            if (pedidos.empty()) {
                cout << "sem pedidos\n";
            } else {
                for (size_t i = 0; i < pedidos.size(); ++i) {
                    cout << pedidos[i];
                    if (i < pedidos.size() - 1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        } else if (acao == "novo") {
            string pedido;
            iss >> pedido;
            pedidos.push_back(pedido);
            cout << "pedido " << pedido << " adicionado\n";
        } else if (acao == "cancela") {
            string pedido;
            iss >> pedido;
            auto it = find(pedidos.begin(), pedidos.end(), pedido);
            if (it != pedidos.end()) {
                pedidos.erase(it);
                cout << "pedido " << pedido << " removido\n";
            } else {
                cout << "pedido " << pedido << " inexistente\n";
            }
        }
    }
    
    return 0;
}
