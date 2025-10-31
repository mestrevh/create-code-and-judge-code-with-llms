/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int B, N;
        cin >> B >> N;
        if (B == 0 && N == 0) break;

        vector<int> reserves(B + 1);
        for (int i = 1; i <= B; ++i) {
            cin >> reserves[i];
        }

        vector<vector<int>> debts(B + 1, vector<int>(B + 1, 0));
        for (int i = 0; i < N; ++i) {
            int D, C, V;
            cin >> D >> C >> V;
            debts[D][C] += V;
        }

        for (int i = 1; i <= B; ++i) {
            for (int j = 1; j <= B; ++j) {
                reserves[i] += debts[j][i];
            }
        }

        bool possible = true;
        for (int i = 1; i <= B; ++i) {
            if (reserves[i] < 0) {
                possible = false;
                break;
            }
        }

        cout << (possible ? 'S' : 'N') << endl;
    }
    return 0;
}
