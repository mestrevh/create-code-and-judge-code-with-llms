/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Product {
    int code;
    string name;
    double price;
    int qty;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Product> products(N);
    unordered_map<int,int> idx;
    idx.reserve(N * 2);

    for (int i = 0; i < N; i++) {
        cin >> products[i].code >> products[i].name >> products[i].price >> products[i].qty;
        idx[products[i].code] = i;
    }

    int M;
    cin >> M;
    for (int opi = 0; opi < M; opi++) {
        string type;
        cin >> type;

        if (type == "Venda") {
            int X;
            cin >> X;
            vector<int> codes(X);
            vector<int> quantities(X);

            for (int i = 0; i < X; i++) cin >> codes[i];
            for (int i = 0; i < X; i++) cin >> quantities[i];

            double Y;
            cin >> Y;

            bool ok = true;
            for (int i = 0; i < X; i++) {
                int c = codes[i];
                int q = quantities[i];
                if (!idx.count(c) || products[idx[c]].qty < q) {
                    ok = false;
                    break;
                }
            }

            if (!ok) {
                cout << "Nao foi possivel realizar a venda\n";
                continue;
            }

            cout.setf(std::ios::fixed);
            cout << setprecision(2);

            double total = 0.0;
            for (int i = 0; i < X; i++) {
                int c = codes[i];
                int q = quantities[i];
                int pi = idx[c];
                double line = products[pi].price * q;
                total += line;
            }

            for (int i = 0; i < X; i++) {
                int c = codes[i];
                int q = quantities[i];
                int pi = idx[c];

                double unit = products[pi].price;
                double line = unit * q;

                cout << products[pi].name << " - R$" << unit << " - " << q << " - R$" << line;
                if (i + 1 < X) cout << "\n";
                products[pi].qty -= q;
            }

            cout << "Total: R$" << total << "\n";
            cout << "Pago: R$" << Y << "\n";
            cout << "Troco: R$" << (Y - total) << "\n";
        } else {
            vector<Product> sorted = products;
            sort(sorted.begin(), sorted.end(), [](const Product& a, const Product& b){
                return a.code < b.code;
            });

            cout << "Estoque atual:\n";
            cout.setf(std::ios::fixed);
            cout << setprecision(2);

            for (int i = 0; i < (int)sorted.size(); i++) {
                cout << (i + 1) << ". " << sorted[i].code << " - " << sorted[i].name << " - " << sorted[i].qty;
                if (i + 1 < (int)sorted.size()) cout << "\n";
            }
            if (opi + 1 < M) cout << "\n";
        }
    }

    return 0;
}