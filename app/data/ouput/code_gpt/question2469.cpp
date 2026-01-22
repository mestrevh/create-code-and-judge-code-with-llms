/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    int I;
    cin >> I;
    cin.ignore();
    map<string, vector<string>> pedidos;
    vector<string> outros;

    for (int i = 0; i < I; i++) {
        string comida, tipo, line;
        getline(cin, line);
        size_t pos = line.find(' ');
        comida = line.substr(0, pos);
        tipo = line.substr(pos + 1);

        if (tipo == "Cafe") pedidos["Chandler"].push_back(comida);
        else if (tipo == "Cha") pedidos["Phoebe"].push_back(comida);
        else if (tipo == "Cerveja") pedidos["Joey"].push_back(comida);
        else if (tipo == "Refrigerante") pedidos["Monica"].push_back(comida);
        else if (tipo == "Suco") pedidos["Ross"].push_back(comida);
        else outros.push_back(comida);
    }

    bool temAmigo = false;
    string amigos[] = {"Chandler", "Phoebe", "Joey", "Monica", "Ross"};

    for (const auto &amigo : amigos) {
        if (pedidos[amigo].empty()) {
            cout << amigo << " não pediu nada." << endl;
        } else {
            cout << amigo << ":" << endl;
            for (const auto &pedido : pedidos[amigo]) {
                cout << "-" << pedido << endl;
            }
            temAmigo = true;
        }
        cout << endl;
    }

    if (temAmigo) {
        if (!outros.empty()) {
            cout << "Outros Clientes:" << endl;
            for (const auto &pedido : outros) {
                cout << "-" << pedido << endl;
            }
        }
    } else {
        cout << "Nenhum dos meus amigos veio, não vou trabalhar hoje." << endl;
    }

    return 0;
}
