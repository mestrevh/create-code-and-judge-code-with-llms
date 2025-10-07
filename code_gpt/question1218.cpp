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
    double vendas[101] = {0}; // Para 1 a 100
    
    for (int i = 0; i < Q; ++i) {
        int V;
        double P;
        cin >> V >> P;
        vendas[V] += P;
    }
    
    int maxVagao = 1;
    double maxTotal = vendas[1];
    
    for (int i = 2; i <= N; ++i) {
        if (vendas[i] > maxTotal) {
            maxTotal = vendas[i];
            maxVagao = i;
        }
    }
    
    cout << maxVagao << " " << fixed << setprecision(1) << maxTotal << endl;
    return 0;
}
