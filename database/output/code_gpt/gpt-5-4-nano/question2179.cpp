/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> indices;
    string nome;
    for (int i = 0; i < 5 && (cin >> nome); i++) {
        int desempenho, gols, cansaco, entrosamento;
        cin >> desempenho >> gols >> cansaco >> entrosamento;

        bool minTwo = (desempenho == 0 && cansaco == 0) ||
                      (desempenho == 0 && entrosamento == 0) ||
                      (cansaco == 0 && entrosamento == 0) ||
                      (desempenho == 0 && desempenho == 0) ||
                      (cansaco == 0 && cansaco == 0) ||
                      (entrosamento == 0 && entrosamento == 0);

        int countMin = 0;
        if (desempenho == 0) countMin++;
        if (cansaco == 0) countMin++;
        if (entrosamento == 0) countMin++;

        if (countMin >= 2) {
            indices.push_back(0.0);
        } else {
            double idx = desempenho * 2.0 + gols * 3.5 + cansaco * 1.5 + entrosamento * 2.0;
            indices.push_back(idx);
        }
    }

    sort(indices.begin(), indices.end(), greater<double>());

    for (int i = 0; i < 3 && i < (int)indices.size(); i++) {
        cout << fixed << setprecision(1) << indices[i] << "\n";
    }

    return 0;
}