/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    double vendas[101] = {0};

    for (int i = 0; i < Q; i++) {
        int V;
        double P;
        cin >> V >> P;
        vendas[V] += P;
    }

    int max_vagao = 1;
    double max_total = vendas[1];

    for (int i = 2; i <= N; i++) {
        if (vendas[i] > max_total) {
            max_total = vendas[i];
            max_vagao = i;
        }
    }

    cout << max_vagao << " " << fixed << setprecision(1) << max_total << endl;
    return 0;
}
