/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
    string produto, sabor;
    int quantidade;

    map<string, map<string, double>> menu = {
        {"Pizza", {{"Calabresa", 20.60}, {"Marguerita", 20.60}, {"Outros sabores", 30.90}}},
        {"Lasanha", {{"Queijo", 18.00}, {"Bolonhesa", 23.00}}}
    };

    cin >> produto;
    cin.ignore();
    getline(cin, sabor);
    cin >> quantidade;

    double preco = menu[produto][sabor];
    double taxaEntrega = 2.0 * quantidade;
    double total = (preco * quantidade) + taxaEntrega;

    cout << fixed << setprecision(2) << total << endl;

    return 0;
}
