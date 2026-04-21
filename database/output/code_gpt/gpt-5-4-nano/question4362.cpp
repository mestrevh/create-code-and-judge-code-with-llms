/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Pedido {
    int mesa;
    string prato;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> climaAcao = {
        "", 
        "Retire os cliente e mesas 21 22 23 24 25 26",
        "prepare as mesas 21 22 23 24 25 26",
        "Retire os cliente das mesas 13 14 15 16 17 18 19 20",
        "Retire os clientes das mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26",
        "Retire os clientes e mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26",
        "Pawb allan, y gweddill yn cael eu tanio"
    };

    unordered_map<string, int> idx;
    idx["Mare alta"] = 1;
    idx["Mare baixa"] = 2;
    idx["chuva leve"] = 3;
    idx["chuva"] = 4;
    idx["Tempestade"] = 5;
    idx["Armagedom"] = 6;

    vector<Pedido> pedidos;
    string token;
    while (cin >> token) {
        if (token == "Fechando") {
            break;
        }
        if (token == "clima") {
            string tipo;
            cin >> tipo;
            auto it = idx.find(tipo);
            if (it != idx.end()) {
                cout << climaAcao[it->second] << "\n";
            }
        } else if (token == "prato") {
            string mesaStr;
            cin >> mesaStr;
            int mesa = stoi(mesaStr);
            string prato;
            cin >> ws;
            getline(cin, prato);
            if (!prato.empty() && prato[0] == ' ') prato.erase(prato.begin());
            pedidos.push_back({mesa, prato});
        }
    }

    for (int i = 0; i < (int)pedidos.size(); i++) {
        cout << "Pedido " << i + 1 << " ,mesa " << pedidos[i].mesa << " ,prato: " << pedidos[i].prato << "\n";
    }
    cout << "tchau";
    return 0;
}