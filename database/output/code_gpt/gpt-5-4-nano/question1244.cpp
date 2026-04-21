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

    unordered_map<string, long long> qty;
    vector<string> order;

    auto ensureOrder = [&](const string& p) {
        if (qty.find(p) == qty.end()) order.push_back(p);
    };

    for (int i = 0; i < N; i++) {
        string C;
        cin >> C;

        if (C == "CADASTRO") {
            string P;
            cin >> P;
            if (qty.find(P) != qty.end()) {
                cout << "Produto ja cadastrado\n";
            } else {
                qty[P] = 0;
                ensureOrder(P);
                cout << "Produto cadastrado com sucesso\n";
            }
        } else if (C == "ESTOQUE") {
            string P;
            long long Q;
            cin >> P >> Q;
            if (qty.find(P) == qty.end()) {
                cout << "Produto não foi cadastrado\n";
            } else {
                qty[P] += Q;
                cout << "Estoque realizado com sucesso\n";
            }
        } else if (C == "VENDA") {
            string P;
            long long Q;
            cin >> P >> Q;
            if (qty.find(P) == qty.end()) {
                cout << "Produto não foi cadastrado\n";
            } else if (qty[P] < Q) {
                cout << "Nao ha estoque para a venda\n";
            } else {
                qty[P] -= Q;
                cout << "Venda realizada com sucesso\n";
            }
        } else {
            cout << "Comando nao reconhecido\n";
        }
    }

    for (size_t i = 0; i < order.size(); i++) {
        const string& p = order[i];
        cout << p << ": " << qty[p];
        if (i + 1 < order.size()) cout << "\n";
    }
    return 0;
}