/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, pair<string, double>> produtos;
    for (int i = 0; i < n; i++) {
        int codigo;
        string descricao;
        double preco;
        cin >> codigo;
        cin.ignore();
        getline(cin, descricao);
        cin >> preco;
        produtos[codigo] = {descricao, preco};
    }

    double total = 0.0;
    while (true) {
        int codigo, quantidade;
        cin >> codigo;
        if (codigo == 0) break;
        cin >> quantidade;
        if (produtos.count(codigo) && quantidade > 0) {
            total += produtos[codigo].second * quantidade;
        }
    }

    cout << fixed << setprecision(2) << total << endl;
    return 0;
}
