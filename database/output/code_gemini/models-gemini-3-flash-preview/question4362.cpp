/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
    int table;
    string dish;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cmd;
    vector<Order> orders;
    while (cin >> cmd && cmd != "Fechando") {
        if (cmd == "prato") {
            int table;
            if (!(cin >> table)) break;
            string dish;
            getline(cin >> ws, dish);
            orders.push_back({table, dish});
        } else if (cmd == "clima") {
            string weather;
            getline(cin >> ws, weather);
            if (weather == "Mare alta") {
                cout << "Retire os cliente e mesas 21 22 23 24 25 26" << endl;
            } else if (weather == "Mare baixa") {
                cout << "prepare as mesas 21 22 23 24 25 26" << endl;
            } else if (weather == "chuva leve" || weather == "chuva baixa") {
                cout << "Retire os cliente das mesas 13 14 15 16 17 18 19 20" << endl;
            } else if (weather == "chuva") {
                cout << "Retire os clientes das mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26" << endl;
            } else if (weather == "Tempestade") {
                cout << "Retire os clientes e mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26" << endl;
            } else if (weather == "Armagedom") {
                cout << "Pawb allan, y gweddill yn cael eu tanio" << endl;
            }
        }
    }

    for (int i = 0; i < (int)orders.size(); ++i) {
        cout << "Pedido " << i + 1 << " ,mesa " << orders[i].table << " ,prato: " << orders[i].dish << endl;
    }
    cout << "tchau" << endl;

    return 0;
}