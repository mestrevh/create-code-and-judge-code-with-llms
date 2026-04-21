/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    double sales[105];
    for (int i = 0; i <= N; ++i) {
        sales[i] = 0.0;
    }

    for (int i = 0; i < Q; ++i) {
        int V;
        double P;
        if (cin >> V >> P) {
            if (V >= 1 && V <= N) {
                sales[V] += P;
            }
        }
    }

    int max_wagon = 1;
    double max_sales = -1.0;

    for (int i = 1; i <= N; ++i) {
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_wagon = i;
        }
    }

    printf("%d %.1f\n", max_wagon, max_sales);

    return 0;
}