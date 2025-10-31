/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdio>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    double sales[101] = {0.0};
    for (int i = 0; i < q; ++i) {
        int v;
        double p;
        std::cin >> v >> p;
        sales[v] += p;
    }
    int max_wagon = 0;
    double max_sales = -1.0;
    for (int i = 1; i <= n; ++i) {
        if (sales[i] > max_sales) {
            max_sales = sales[i];
            max_wagon = i;
        }
    }
    printf("%d %.1f\n", max_wagon, max_sales);
    return 0;
}
