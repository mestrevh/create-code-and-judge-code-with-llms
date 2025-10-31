/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> consultas(N);

    for (int i = 0; i < N; i++) {
        cin >> consultas[i].first >> consultas[i].second;
    }

    sort(consultas.begin(), consultas.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int maxConsultas = 0;
    int ultimoFim = 0;

    for (const auto& consulta : consultas) {
        if (consulta.first >= ultimoFim) {
            maxConsultas++;
            ultimoFim = consulta.second;
        }
    }

    cout << maxConsultas << endl;
    return 0;
}
