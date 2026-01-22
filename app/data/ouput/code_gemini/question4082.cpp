/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <limits>

using namespace std;

const double BRL_TO_USD = 5.17;

struct Product {
    string name;
    double price_brl;
};

struct Transaction {
    string buyer;
    string country;
    string continent;
    int product_id;
    int lots;
};

void initialize_data(map<int, Product>& products, map<string, double>& shipping_costs) {
    products[101] = {"Abacaxi", 103.45};
    products[234] = {"Banana", 89.90};
    products[356] = {"Cafe", 345.89};
    products[411] = {"Caju", 112.78};
    products[702] = {"Laranja", 179.53};
    products[589] = {"Melancia", 153.21};
    products[642] = {"Soja", 540.00};
    products[809] = {"Trigo", 621.32};
    products[923] = {"Carne Bovina", 2319.43};
    products[957] = {"Carne Suina", 1789.12};

    shipping_costs["Africa"] = 389.00;
    shipping_costs["America"] = 150.00;
    shipping_costs["Asia"] = 573.00;
    shipping_costs["Europa"] = 412.00;
    shipping_costs["Oceania"] = 699.00;
}

void process_transaction(const Transaction& t,
                         const map<int, Product>& products,
                         const map<string, double>& shipping_costs) {
    
    auto product_it = products.find(t.product_id);
    if (product_it == products.end()) {
        cout << "Operacao invalida!" << endl;
        return;
    }

    auto shipping_it = shipping_costs.find(t.continent);
    if (shipping_it == shipping_costs.end()) {
        cout << "Operacao invalida!" << endl;
        return;
    }
    
    const Product& product = product_it->second;
    double shipping_brl = shipping_it->second;

    double product_cost_brl = product.price_brl * t.lots;
    
    double product_cost_usd = product_cost_brl / BRL_TO_USD;
    double shipping_cost_usd = shipping_brl / BRL_TO_USD;
    double total_cost_usd = product_cost_usd + shipping_cost_usd;

    cout << t.buyer << endl;
    cout << t.country << endl;
    cout << product.name << endl;
    cout << "Valor do produto: U$ " << product_cost_usd << endl;
    cout << "Valor do frete: U$ " << shipping_cost_usd << endl;
    cout << "Valor total: U$ " << total_cost_usd << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(2);

    map<int, Product> products;
    map<string, double> shipping_costs;
    initialize_data(products, shipping_costs);

    int n;
    cin >> n;

    if (n == 0) {
        cout << "Sem negociacoes por hoje!" << endl;
        return 0;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        Transaction t;
        getline(cin, t.buyer);
        getline(cin, t.country);
        cin >> t.continent >> t.product_id >> t.lots;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        process_transaction(t, products, shipping_costs);
    }

    return 0;
}
