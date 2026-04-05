/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<string> order;
    map<string, long long> stock;

    auto printInvalid = [&]() {
        cout << "Comando inválido\n";
    };

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "CADASTRO") {
            string p;
            getline(cin, p); 
            while (p.size() == 0) {
                getline(cin, p);
            }
            if (!p.empty() && p[0] == ' ') p.erase(0, p.find_first_not_of(' '));
            if (p.empty()) {
                printInvalid();
                continue;
            }
            if (stock.count(p)) {
                cout << "Produto já cadastrado\n";
            } else {
                stock[p] = 0;
                order.push_back(p);
                cout << "Produto cadastrado com sucesso\n";
            }
        } else if (cmd == "ESTOQUE" || cmd == "VENDA") {
            string p;
            getline(cin, p);
            while (p.size() == 0) {
                getline(cin, p);
            }
            if (!p.empty() && p[0] == ' ') p.erase(0, p.find_first_not_of(' '));
            long long q;
            cin >> q;

            if (q < 0) {
                printInvalid();
                continue;
            }

            if (cmd == "ESTOQUE") {
                if (!stock.count(p)) {
                    cout << "Produto não foi cadastrado\n";
                } else {
                    stock[p] += q;
                    cout << "Estoque realizado com sucesso\n";
                }
            } else {
                if (!stock.count(p)) {
                    cout << "Produto não foi cadastrado\n";
                } else if (stock[p] < q) {
                    cout << "Não há estoque para a venda\n";
                } else {
                    stock[p] -= q;
                    cout << "Venda realizada com sucesso\n";
                }
            }
        } else {
            printInvalid();
            if (cmd == "CADASTRO") continue;
        }
    }

    for (size_t i = 0; i < order.size(); i++) {
        const string &p = order[i];
        cout << p << ": " << stock[p];
        if (i + 1 < order.size()) cout << "\n";
    }

    return 0;
}