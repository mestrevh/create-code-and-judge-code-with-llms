/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    // O problema exige o uso de array. N <= 100, então 105 é suficiente.
    double sales[105];
    for (int i = 0; i < 105; ++i) {
        sales[i] = 0.0;
    }

    for (int i = 0; i < Q; ++i) {
        int V;
        double P;
        cin >> V >> P;
        // Acumula as vendas do vagão V. V está no intervalo [1, N].
        if (V >= 1 && V <= N) {
            sales[V] += P;
        }
    }

    int max_wagon = 1;
    double max_total = -1.0;

    // Identifica o vagão com o maior volume total de vendas.
    for (int i = 1; i <= N; ++i) {
        if (sales[i] > max_total) {
            max_total = sales[i];
            max_wagon = i;
        }
    }

    // Saída formatada conforme solicitado (uma casa decimal).
    printf("%d %.1f\n", max_wagon, max_total);

    return 0;
}