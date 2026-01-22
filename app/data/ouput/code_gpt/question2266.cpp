/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M && (N || M)) {
        vector<string> desenho(N);
        for (int i = 0; i < N; ++i) {
            cin >> desenho[i];
        }
        int A, B;
        cin >> A >> B;
        
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < A / N; ++k) {
                for (int j = 0; j < M; ++j) {
                    for (int l = 0; l < B / M; ++l) {
                        cout << desenho[i][j];
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
