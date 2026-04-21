/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Product {
    string name;
    long long stock;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<Product> products;
    unordered_map<string, int> idx;

    auto toLower = [](string s){
        for(char &c: s) c = (char)tolower((unsigned char)c);
        return s;
    };

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        string upper = cmd;
        for (char &c : upper) c = (char)toupper((unsigned char)c);

        if (upper == "CADASTRO") {
            string p;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, p);
            p.erase(0, p.find_first_not_of(" \t\r\n"));
            p.erase(p.find_last_not_of(" \t\r\n") + 1);
            string key = p;

            if (idx.find(key) == idx.end()) {
                idx[key] = (int)products.size();
                products.push_back({p, 0});
                cout << "Produto cadastrado com sucesso\n";
            } else {
                cout << "Produto ja cadastrado\n";
            }
        } else if (upper == "VENDA") {
            string p;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, p);
            p.erase(0, p.find_first_not_of(" \t\r\n"));
            p.erase(p.find_last_not_of(" \t\r\n") + 1);
            long long q;
            cin >> q;

            auto it = idx.find(p);
            if (it == idx.end()) {
                cout << "Produto nao foi cadastrado\n";
            } else {
                int id = it->second;
                if (products[id].stock < q) {
                    cout << "Nao ha estoque para a venda\n";
                } else {
                    products[id].stock -= q;
                    cout << "Venda realizada com sucesso\n";
                }
            }
        } else if (upper == "ESTOQUE") {
            string p;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, p);
            p.erase(0, p.find_first_not_of(" \t\r\n"));
            p.erase(p.find_last_not_of(" \t\r\n") + 1);
            long long q;
            cin >> q;

            auto it = idx.find(p);
            if (it == idx.end()) {
                cout << "Produto nao foi cadastrado\n";
            } else {
                products[it->second].stock += q;
                cout << "Estoque realizado com sucesso\n";
            }
        } else {
            cout << "Comando invalido\n";
            if (cmd == "VENDA" || cmd == "ESTOQUE" || cmd == "CADASTRO") {
                continue;
            }
        }
    }

    for (size_t i = 0; i < products.size(); i++) {
        cout << products[i].name << ": " << products[i].stock;
        if (i + 1 < products.size()) cout << "\n";
    }

    return 0;
}