/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

struct Sala {
    int id;
    int aprovados;
    int ordem;
};

bool compareSalas(const Sala& a, const Sala& b) {
    if (a.aprovados != b.aprovados) {
        return a.aprovados > b.aprovados;
    }
    return a.ordem < b.ordem;
}

int main() {
    int n;
    cin >> n;

    vector<Sala> salas(n);
    for (int i = 0; i < n; ++i) {
        int id, q;
        cin >> id >> q;
        salas[i].id = id;
        salas[i].ordem = i;
        salas[i].aprovados = 0;

        for (int j = 0; j < q; ++j) {
            string nome;
            double presenca;
            cin >> nome >> presenca;

            vector<int> notas_mat(3);
            vector<int> notas_port(3);
            vector<int> notas_hist(3);

            for (int k = 0; k < 3; ++k) cin >> notas_mat[k];
            for (int k = 0; k < 3; ++k) cin >> notas_port[k];
            for (int k = 0; k < 3; ++k) cin >> notas_hist[k];

            double media_mat = accumulate(notas_mat.begin(), notas_mat.end(), 0.0) / 3.0;
            double media_port = accumulate(notas_port.begin(), notas_port.end(), 0.0) / 3.0;
            double media_hist = accumulate(notas_hist.begin(), notas_hist.end(), 0.0) / 3.0;

            if (media_mat >= 7 && media_port >= 7 && media_hist >= 7 && presenca >= 0.75) {
                salas[i].aprovados++;
            }
        }
    }

    sort(salas.begin(), salas.end(), compareSalas);

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". [SALA #" << salas[i].id << "] APROVADOS: " << salas[i].aprovados << endl;
    }

    return 0;
}
