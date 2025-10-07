/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string command;
    vector<pair<int, string>> orders;

    while (cin >> command && command != "Fechando") {
        if (command == "prato") {
            int table;
            string dish;
            cin >> table;
            getline(cin >> ws, dish);
            orders.push_back({table, dish});
        } else if (command == "clima") {
            string weather;
            cin >> weather;
            if (weather == "Mare alta") {
                cout << "Retire os cliente e mesas 21 22 23 24 25 26" << endl;
            } else if (weather == "Mare baixa") {
                cout << "prepare as mesas 21 22 23 24 25 26" << endl;
            } else if (weather == "chuva baixa" || weather == "chuva leve") {
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

    for (int i = 0; i < orders.size(); ++i) {
        cout << "Pedido " << i + 1 << " ,mesa " << orders[i].first << " ,prato: " << orders[i].second << endl;
    }
    cout << "tchau" << endl;

    return 0;
}
