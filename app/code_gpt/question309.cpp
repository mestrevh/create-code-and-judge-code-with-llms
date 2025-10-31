/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n, cidade = 1;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> imoveis(n);
        double total_consumo = 0;
        int total_pessoas = 0;

        for (int i = 0; i < n; i++) {
            cin >> imoveis[i].first >> imoveis[i].second;
            total_consumo += imoveis[i].second;
            total_pessoas += imoveis[i].first;
        }

        map<int, int> consumo_por_pessoa;
        for (const auto& imovel : imoveis) {
            int media = imovel.second / imovel.first;
            consumo_por_pessoa[media] += imovel.first;
        }

        cout << "Cidade# " << cidade++ << ":\n";
        for (const auto& [consumo, pessoas] : consumo_por_pessoa) {
            cout << pessoas << "-" << consumo << " ";
        }
        cout << "\nConsumo medio: " << fixed << setprecision(2) << total_consumo / total_pessoas << " m3.\n\n";
    }
    return 0;
}
