/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> pedidos;
    string entrada;
    int mesa;
    string prato;
    
    while (true) {
        cin >> entrada;
        if (entrada == "Fechando") break;
        if (entrada == "prato") {
            cin >> mesa;
            cin.ignore();
            getline(cin, prato);
            pedidos.push_back("Pedido " + to_string(pedidos.size() + 1) + ",mesa " + to_string(mesa) + ",prato: " + prato);
        } else if (entrada == "clima") {
            string clima;
            cin.ignore();
            getline(cin, clima);
            if (clima == "Mare alta") {
                cout << "Retire os cliente e mesas 21 22 23 24 25 26" << endl;
            } else if (clima == "Mare baixa") {
                cout << "prepare as mesas 21 22 23 24 25 26" << endl;
            } else if (clima == "chuva baixa") {
                cout << "Retire os cliente das mesas 13 14 15 16 17 18 19 20" << endl;
            } else if (clima == "chuva") {
                cout << "Retire os clientes das mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26" << endl;
            } else if (clima == "Tempestade") {
                cout << "Retire os clientes e mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26" << endl;
            } else if (clima == "Armagedom") {
                cout << "Pawb allan, y gweddill yn cael eu tanio" << endl;
            }
        }
    }

    for (const auto& pedido : pedidos) {
        cout << pedido << endl;
    }
    cout << "tchau" << endl;
    
    return 0;
}
