/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> caminhaoNecessario(N), dias(N), custo(N);
    int totalCaminhoes = 0, totalCusto = 0, maxDias = 0;

    for (int i = 0; i < N; i++) {
        int peso, entrega, distancia;
        cin >> peso >> entrega >> distancia;

        int limitePeso = entrega == 1 ? 5 : 10;
        int precoCaminhao = entrega == 1 ? 1200 : 500;

        caminhaoNecessario[i] = ceil((double)peso / limitePeso);
        dias[i] = ceil((double)distancia / (entrega == 1 ? 250 : 100));
        
        totalCaminhoes += caminhaoNecessario[i];
        totalCusto += caminhaoNecessario[i] * precoCaminhao;
        maxDias = max(maxDias, dias[i]);
    }

    cout << totalCaminhoes << " " << totalCusto << " " << maxDias << endl;
    return 0;
}
