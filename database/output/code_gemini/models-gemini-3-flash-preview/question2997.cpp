/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

struct Product {
    double price;
    int quantity;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, Product> shopping_list;
    string command;

    while (cin >> command) {
        if (command == "INSERIR") {
            string name;
            double price;
            int qty;
            if (!(cin >> name >> price >> qty)) break;
            if (shopping_list.count(name)) {
                shopping_list[name].quantity += qty;
                shopping_list[name].price = price;
            } else {
                shopping_list[name] = {price, qty};
            }
        } else if (command == "REMOVER") {
            string name;
            int qty;
            if (!(cin >> name >> qty)) break;
            if (shopping_list.count(name)) {
                shopping_list[name].quantity -= qty;
                if (shopping_list[name].quantity <= 0) {
                    shopping_list.erase(name);
                }
            }
        } else if (command == "REMOVERGRUPO") {
            double limit;
            if (!(cin >> limit)) break;
            for (auto it = shopping_list.begin(); it != shopping_list.end(); ) {
                if (it->second.price > limit) {
                    it = shopping_list.erase(it);
                } else {
                    ++it;
                }
            }
        } else if (command == "CONSULTAR") {
            double total = 0;
            for (auto const& item_pair : shopping_list) {
                total += item_pair.second.price * (double)item_pair.second.quantity;
            }
            cout << "Atualmente a lista esta em R$" << fixed << setprecision(1) << total << "\n\n";
        } else if (command == "PROCURAR") {
            string name;
            if (!(cin >> name)) break;
            if (shopping_list.count(name)) {
                cout << name << " - " << fixed << setprecision(1) << shopping_list[name].price << " - " << shopping_list[name].quantity << "\n\n";
            } else {
                cout << name << " nao foi encontrado\n\n";
            }
        }
    }

    return 0;
}