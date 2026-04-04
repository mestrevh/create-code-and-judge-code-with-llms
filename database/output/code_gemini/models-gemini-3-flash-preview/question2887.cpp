/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int caseNum = 1;
    while (cout << "Digite o numero de genes do genoma entre 1 e 500:" << endl && cin >> N && N != 0) {
        vector<int> genome(N + 1);
        for (int k = 1; k <= N; ++k) {
            genome[k] = k;
        }

        int R;
        cout << "Digite o numero de reversas entre 1 e 100:" << endl;
        if (!(cin >> R)) break;

        for (int k = 0; k < R; ++k) {
            int i, j;
            cout << "Digite a posicao inicial da reversa:" << endl;
            if (!(cin >> i)) break;
            cout << "Digite a posicao final da reversa:" << endl;
            if (!(cin >> j)) break;
            if (i > j) {
                int temp = i;
                i = j;
                j = temp;
            }
            if (i >= 1 && j <= N) {
                reverse(genome.begin() + i, genome.begin() + j + 1);
            }
        }

        int Q;
        cout << "Digite o numero de consultas:" << endl;
        if (!(cin >> Q)) break;

        cout << "Genome " << caseNum++ << endl;
        for (int k = 0; k < Q; ++k) {
            int pos;
            cout << "Digite a posicao a ser consultada entre 1 e " << N << ":" << endl;
            if (!(cin >> pos)) break;
            if (pos >= 1 && pos <= N) {
                cout << "Posicao " << pos << ": " << genome[pos] << endl;
            }
        }
    }

    return 0;
}