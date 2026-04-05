/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    struct Sala {
        int id;
        int aprovados;
        int pos;
    };

    vector<Sala> salas;
    salas.reserve(n);

    for (int i = 0; i < n; i++) {
        int id, q;
        cin >> id >> q;

        int cnt = 0;
        for (int j = 0; j < q; j++) {
            string nome;
            double pres;
            cin >> nome >> pres;

            vector<int> math(3), port(3), hist(3);
            for (int k = 0; k < 3; k++) cin >> math[k];
            for (int k = 0; k < 3; k++) cin >> port[k];
            for (int k = 0; k < 3; k++) cin >> hist[k];

            auto avg = [](const vector<int>& v) -> double {
                return (v[0] + v[1] + v[2]) / 3.0;
            };

            double mAvg = avg(math);
            double pAvg = avg(port);
            double hAvg = avg(hist);

            if (pres >= 0.75 && mAvg >= 7.0 && pAvg >= 7.0 && hAvg >= 7.0) cnt++;
        }

        salas.push_back({id, cnt, i});
    }

    stable_sort(salas.begin(), salas.end(), [](const Sala& a, const Sala& b) {
        if (a.aprovados != b.aprovados) return a.aprovados > b.aprovados;
        return a.pos < b.pos;
    });

    for (int i = 0; i < (int)salas.size(); i++) {
        cout << (i + 1) << ". [SALA #" << salas[i].id << "] APROVADOS: " << salas[i].aprovados;
        if (i + 1 < (int)salas.size()) cout << "\n";
    }

    return 0;
}