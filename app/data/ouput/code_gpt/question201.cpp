/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Carro {
    int id;
    int tempo_total;
};

bool comparar(Carro a, Carro b) {
    return a.tempo_total < b.tempo_total;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Carro> carros(N);

    for (int i = 0; i < N; i++) {
        carros[i].id = i + 1;
        carros[i].tempo_total = 0;
        for (int j = 0; j < M; j++) {
            int tempo;
            cin >> tempo;
            carros[i].tempo_total += tempo;
        }
    }

    sort(carros.begin(), carros.end(), comparar);

    cout << carros[0].id << endl;
    cout << carros[1].id << endl;
    cout << carros[2].id << endl;

    return 0;
}
