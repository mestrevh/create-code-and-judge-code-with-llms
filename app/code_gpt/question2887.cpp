/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

void reverse_segment(vector<int>& genome, int i, int j) {
    while (i < j) {
        swap(genome[i], genome[j]);
        i++;
        j--;
    }
}

int main() {
    int case_number = 1;
    while (true) {
        cout << "Digite o numero de genes do genoma entre 1 e 500:" << endl;
        int N;
        cin >> N;
        if (N == 0) break;

        vector<int> genome(N);
        for (int i = 0; i < N; i++) {
            genome[i] = i + 1;
        }

        cout << "Digite o numero de reversas entre 1 e 100:" << endl;
        int R;
        cin >> R;

        for (int r = 0; r < R; r++) {
            cout << "Digite a posicao inicial da reversa:" << endl;
            int i;
            cin >> i;
            cout << "Digite a posicao final da reversa:" << endl;
            int j;
            cin >> j;
            reverse_segment(genome, i - 1, j - 1);
        }

        cout << "Digite o numero de consultas:" << endl;
        int Q;
        cin >> Q;
        cout << "Genome " << case_number++ << endl;

        for (int q = 0; q < Q; q++) {
            cout << "Digite a posicao a ser consultada entre 1 e " << N << ":" << endl;
            int pos;
            cin >> pos;
            cout << "Posicao " << pos << ": " << genome[pos - 1] << endl;
        }
    }
    return 0;
}
