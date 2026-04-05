/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string gabarito;
    if (!(cin >> gabarito)) return 0;

    vector<int> freq(11, 0);
    int aprovadoCount = 0;
    int totalAlunos = 0;

    int aluno;
    while (cin >> aluno) {
        if (aluno == 9999) break;
        string resp;
        cin >> resp;

        int nota = 0;
        for (int i = 0; i < 10; i++) {
            if (resp[i] == gabarito[i]) nota++;
        }

        freq[nota]++;
        totalAlunos++;
        if (nota >= 6) aprovadoCount++;

        cout << aluno << " " << fixed << setprecision(1) << nota << ".0\n";
    }

    double percent = totalAlunos == 0 ? 0.0 : (100.0 * aprovadoCount) / totalAlunos;
    cout << fixed << setprecision(1) << percent << "%\n";

    int bestNota = 0;
    int bestFreq = -1;
    for (int i = 0; i <= 10; i++) {
        if (freq[i] > bestFreq) {
            bestFreq = freq[i];
            bestNota = i;
        }
    }

    cout << fixed << setprecision(1) << bestNota << ".0\n";
    return 0;
}