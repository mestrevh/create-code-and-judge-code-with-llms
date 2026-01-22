/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> casas(N);
    for (int i = 0; i < N; ++i) cin >> casas[i];

    vector<int> pedidos(M);
    for (int i = 0; i < M; ++i) cin >> pedidos[i];

    // Mapeia cada número de casa para a posição no vetor ordenado
    // Usando lower_bound já que são ordenadas e distintas
    int curr = 0; // começa na primeira casa (casas[0])
    long long tempo = 0;
    for (int i = 0; i < M; ++i) {
        int idx = lower_bound(casas.begin(), casas.end(), pedidos[i]) - casas.begin();
        tempo += abs(idx - curr);
        curr = idx;
    }
    cout << tempo << endl;
    return 0;
}
