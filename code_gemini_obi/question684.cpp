/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> casas(N);
    map<int, int> indice;
    for (int i = 0; i < N; ++i) {
        cin >> casas[i];
        indice[casas[i]] = i;
    }

    vector<int> encomendas(M);
    for (int i = 0; i < M; ++i)
        cin >> encomendas[i];

    int tempo = 0, atual = 0;
    for (int i = 0; i < M; ++i) {
        int prox = indice[encomendas[i]];
        tempo += abs(prox - atual);
        atual = prox;
    }
    cout << tempo << '\n';
    return 0;
}
