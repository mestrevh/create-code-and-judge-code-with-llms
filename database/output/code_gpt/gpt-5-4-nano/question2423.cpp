/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    long long T1, V1, T2, V2, T3, V3;
    if (!(cin >> N >> M)) return 0;
    cin >> T1 >> V1 >> T2 >> V2 >> T3 >> V3;

    long long ideal = 2 * M + 7;

    if (ideal > M) {
        cout << "Não cantarei, desculpa.";
        return 0;
    }

    long long bestV = V1;
    int bestIdx = 1;

    if (V2 < bestV || (V2 == bestV && 2 < bestIdx)) {
        bestV = V2;
        bestIdx = 2;
    }
    if (V3 < bestV || (V3 == bestV && 3 < bestIdx)) {
        bestV = V3;
        bestIdx = 3;
    }

    cout << "Você deve cantar a música " << bestIdx << ", boa sorte!";
    return 0;
}