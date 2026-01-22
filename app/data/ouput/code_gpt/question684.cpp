/*
Código criado pelo modelo gpt-4.1
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> casas(N);
    unordered_map<int, int> pos;
    for (int i = 0; i < N; ++i) {
        cin >> casas[i];
        pos[casas[i]] = i;
    }
    vector<int> encomendas(M);
    for (int i = 0; i < M; ++i) cin >> encomendas[i];

    int tempo = 0;
    int atual = pos[casas[0]];
    for (int i = 0; i < M; ++i) {
        int prox = pos[encomendas[i]];
        tempo += abs(prox - atual);
        atual = prox;
    }
    cout << tempo << endl;
    return 0;
}
