/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int P, N, C;
    while (cin >> P >> N >> C, P || N || C) {
        vector<vector<int>> measurements(N, vector<int>(P));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < P; ++j) {
                cin >> measurements[i][j];
            }
        }

        int totalPalitos = 0;
        for (int j = 0; j < P; ++j) {
            int count = 0;
            for (int i = 0; i < N; ++i) {
                if (measurements[i][j] == 1) {
                    count++;
                } else {
                    if (count >= C) totalPalitos++;
                    count = 0;
                }
            }
            if (count >= C) totalPalitos++;
        }
        cout << totalPalitos << endl;
    }
    return 0;
}
