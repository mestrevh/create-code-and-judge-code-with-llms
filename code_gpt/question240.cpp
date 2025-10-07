/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }
        
        int inversions = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (P[i] > P[j]) {
                    ++inversions;
                }
            }
        }
        
        cout << (inversions % 2 == 0 ? "Carlos" : "Marcelo") << endl;
    }
    return 0;
}
