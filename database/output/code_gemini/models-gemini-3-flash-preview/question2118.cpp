/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    string dummy;
    getline(cin, dummy);

    vector<string> registryOrder;
    map<string, long long> stock;
    map<string, bool> isRegistered;

    for (int i = 0; i < n; ++i) {
        string cmd;
        if (!getline(cin, cmd)) break;

        if (cmd == "CADASTRO") {
            string product;
            if (!getline(cin, product)) break;
            if (isRegistered[product]) {
                cout << "Produto já cadastrado" << endl;
            } else {
                isRegistered[product] = true;
                registryOrder.push_back(product);
                stock[product] = 0;
                cout << "Produto cadastrado com sucesso" << endl;
            }
        } else if (cmd == "ESTOQUE") {
            string product;
            if (!getline(cin, product)) break;
            long long q;
            if (!(cin >> q)) break;
            getline(cin, dummy);
            if (q < 0) {
                cout << "Comando inválido" << endl;
            } else if (!isRegistered[product]) {
                cout << "Produto não foi cadastrado" << endl;
            } else {
                stock[product] += q;
                cout << "Estoque realizado com sucesso" << endl;
            }
        } else if (cmd == "VENDA") {
            string product;
            if (!getline(cin, product)) break;
            long long q;
            if (!(cin >> q)) break;
            getline(cin, dummy);
            if (q < 0) {
                cout << "Comando inválido" << endl;
            } else if (!isRegistered[product]) {
                cout << "Produto não foi cadastrado" << endl;
            } else if (stock[product] < q) {
                cout << "Não há estoque para a venda" << endl;
            } else {
                stock[product] -= q;
                cout << "Venda realizada com sucesso" << endl;
            }
        } else {
            cout << "Comando inválido" << endl;
        }
    }

    for (const string& s : registryOrder) {
        cout << s << ": " << stock[s] << endl;
    }

    return 0;
}