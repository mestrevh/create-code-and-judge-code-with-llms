/*
Código criado pelo modelo gemini-2.5-pro
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
    for(int i = 0; i < N; ++i) cin >> casas[i];

    vector<int> encomendas(M);
    for(int i = 0; i < M; ++i) cin >> encomendas[i];

    int tempo = 0, pos = 0;
    vector<int>::iterator it = casas.begin();
    int currCasa = casas[0];

    for(int i = 0; i < M; ++i) {
        // Encontrar o índice da casa para a encomenda atual
        it = lower_bound(casas.begin(), casas.end(), encomendas[i]);
        int idx = it - casas.begin();
        int nextCasa = casas[idx];
        tempo += abs(currCasa - nextCasa);
        currCasa = nextCasa;
    }

    cout << tempo << endl;
    return 0;
}
