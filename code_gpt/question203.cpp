/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> stones(N, 0);
    
    for (int i = 0; i < M; i++) {
        int P, D;
        cin >> P >> D;
        for (int j = P; j >= 1; j -= D) {
            stones[j - 1] = 1;
        }
        for (int j = P; j <= N; j += D) {
            stones[j - 1] = 1;
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << stones[i] << endl;
    }
    
    return 0;
}
