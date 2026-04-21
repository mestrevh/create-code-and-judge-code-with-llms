/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string gabarito;
    if (!(cin >> gabarito)) return 0;

    int id;
    int total_alunos = 0;
    int aprovados = 0;
    vector<int> freq(11, 0);

    cout << fixed << setprecision(1);

    while (cin >> id && id != 9999) {
        string respostas;
        cin >> respostas;

        int nota = 0;
        for (int i = 0; i < 10; ++i) {
            if (respostas[i] == gabarito[i]) {
                nota++;
            }
        }

        cout << id << " " << (double)nota << "\n";

        total_alunos++;
        if (nota >= 6) {
            aprovados++;
        }
        freq[nota]++;
    }

    if (total_alunos > 0) {
        double pct_aprovacao = (double)aprovados * 100.0 / total_alunos;
        cout << pct_aprovacao << "%\n";

        int max_freq = -1;
        int nota_moda = 0;
        for (int i = 0; i <= 10; ++i) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                nota_moda = i;
            }
        }
        cout << (double)nota_moda << "\n";
    }

    return 0;
}

