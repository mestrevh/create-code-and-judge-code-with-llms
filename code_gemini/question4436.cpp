/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    vector<tuple<string, double, int>> products(n);
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        string name;
        double price;
        int quantity;
        size_t space1 = line.find(' ');
        name = line.substr(0, space1);
        size_t space2 = line.find(' ', space1 + 1);
        price = stod(line.substr(space1 + 1, space2 - space1 - 1));
        quantity = stoi(line.substr(space2 + 1));
        products[i] = make_tuple(name, price, quantity);
    }

    string date_line;
    getline(cin, date_line);
    string paid_line;
    getline(cin, paid_line);

    string date = date_line.substr(date_line.find("dia ") + 4, 5);
    double paid = stod(paid_line.substr(paid_line.find("R$") + 2));

    cout << "=============" << endl;
    cout << "NF - 0123" << endl;
    cout << "Data - " << date << endl;
    cout << "=============" << endl;

    double total = 0;
    for (const auto& product : products) {
        cout << get<2>(product) << "x " << get<0>(product) << " - R$" << fixed << setprecision(2) << get<2>(product) * get<1>(product) << endl;
        total += get<2>(product) * get<1>(product);
    }

    cout << endl;
    cout << "Valor Total - R$" << fixed << setprecision(2) << total << endl;
    cout << "Pago - R$" << fixed << setprecision(2) << paid << endl;
    cout << "Troco - R$" << fixed << setprecision(2) << paid - total << endl;
    cout << "=============";

    return 0;
}
