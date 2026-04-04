/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double weight;
    while (cin >> weight) {
        if (weight > 0) {
            cout << "Peso valido!" << endl;
            break;
        } else {
            cout << "Peso invalido!" << endl;
        }
    }

    double l, w, d;
    while (cin >> l >> w >> d) {
        if (l > 0 && w > 0 && d > 0) {
            cout << "Dimensoes validas!" << endl;
            break;
        } else {
            cout << "Dimensoes invalidas!" << endl;
        }
    }

    double max_dim = l;
    if (w > max_dim) max_dim = w;
    if (d > max_dim) max_dim = d;
    
    double sum_dim = l + w + d;

    if (weight > 500.0 || max_dim > 28.0 || sum_dim > 52.0) {
        cout << "Este pacote nao atende os limites para envio no caixa de autoatendimento, dirija-se ao balcao de atendimento para posta-lo!" << endl;
    } else {
        double weight_cost = ceil(weight / 100.0) * 0.50;
        double size_cost = (floor(sum_dim) - 5.0) * 0.05;
        double total_cost = weight_cost + size_cost;
        cout << "Custo total do envio: R$ " << fixed << setprecision(2) << total_cost << endl;
    }

    return 0;
}