/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    while (cin >> N >> K) {
        vector<int> notas(N);
        for (int i = 0; i < N; ++i) {
            cin >> notas[i];
        }
        sort(notas.rbegin(), notas.rend());
        long long soma = 0;
        for (int i = 0; i < K; ++i) {
            soma += notas[i];
        }
        cout << soma << endl;
    }
    return 0;
}
