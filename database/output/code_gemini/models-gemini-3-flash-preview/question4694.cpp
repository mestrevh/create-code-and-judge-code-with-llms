/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

struct Product {
    int code;
    string name;
    double price;
    int qty;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<Product> products(n);
    map<int, int> code_to_idx;
    for (int i = 0; i < n; ++i) {
        cin >> products[i].code >> products[i].name >> products[i].price >> products[i].qty;
    }
    
    for (int i = 0; i < n; ++i) {
        code_to_idx[products[i].code] = i;
    }

    int m;
    if (!(cin >> m)) return 0;
    
    while (m--) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "Venda") {
            int x;
            cin >> x;
            vector<pair<int, int>> sale_items(x);
            map<int, int> sale_demand;
            bool possible = true;
            
            for (int i = 0; i < x; ++i) {
                cin >> sale_items[i].first >> sale_items[i].second;
                int code = sale_items[i].first;
                int q = sale_items[i].second;
                sale_demand[code] += q;
                if (code_to_idx.find(code) == code_to_idx.end()) {
                    possible = false;
                }
            }
            
            if (possible) {
                for (auto const& p : sale_demand) {
                    int code = p.first;
                    int demand = p.second;
                    if (products[code_to_idx[code]].qty < demand) {
                        possible = false;
                        break;
                    }
                }
            }
            
            double paid;
            cin >> paid;
            
            if (!possible) {
                cout << "Nao foi possivel realizar a venda" << endl;
            } else {
                double total = 0;
                cout << fixed << setprecision(2);
                for (int i = 0; i < x; ++i) {
                    int code = sale_items[i].first;
                    int q = sale_items[i].second;
                    int idx = code_to_idx[code];
                    double line_total = products[idx].price * q;
                    total += line_total;
                    cout << products[idx].name << " - R$" << products[idx].price << " - " << q << " - R$" << line_total << "\n";
                    products[idx].qty -= q;
                }
                cout << "Total: R$" << total << "\n";
                cout << "Pago: R$" << paid << "\n";
                cout << "Troco: R$" << (paid - total) << "\n";
            }
        } else if (cmd == "Estoque") {
            vector<Product> sorted_products = products;
            sort(sorted_products.begin(), sorted_products.end(), [](const Product& a, const Product& b) {
                return a.name < b.name;
            });
            
            cout << "Estoque atual:\n";
            for (int i = 0; i < (int)sorted_products.size(); ++i) {
                cout << (i + 1) << ". " << sorted_products[i].code << " - " << sorted_products[i].name << " - " << sorted_products[i].qty << "\n";
            }
        }
    }
    
    return 0;
}