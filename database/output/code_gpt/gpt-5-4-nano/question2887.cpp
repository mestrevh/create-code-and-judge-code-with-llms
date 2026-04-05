/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int tc = 1;
    while (true) {
        cout << "Digite o numero de genes do genoma entre 1 e 500:";
        if (!(cin >> N)) return 0;
        if (N == 0) break;

        vector<int> genome(N);
        iota(genome.begin(), genome.end(), 1);

        cout << "Digite o numero de reversas entre 1 e 100:";
        int R;
        cin >> R;
        for (int k = 0; k < R; k++) {
            cout << "Digite a posicao inicial da reversa:";
            int i, j;
            cin >> i;
            cout << "Digite a posicao final da reversa:";
            cin >> j;
            reverse(genome.begin() + (i - 1), genome.begin() + j);
        }

        cout << "Digite o número de consultas:";
        int Q;
        cin >> Q;

        cout << "Genome " << tc++ << "\n";
        for (int k = 0; k < Q; k++) {
            cout << "Digite a posicao a ser consultada entre 1 e " << N << ":\n";
            int pos;
            cin >> pos;
            cout << "Posicao " << pos << ": " << genome[pos - 1] << "\n";
        }
    }
    return 0;
}