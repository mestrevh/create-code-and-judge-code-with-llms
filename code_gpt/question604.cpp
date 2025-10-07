/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    vector<int> olives(N);
    for (int i = 0; i < N; ++i) {
        cin >> olives[i];
    }
    
    for (int i = 0; i < N; ++i) {
        if ((olives[(i + 1) % N] - olives[i] + C) % C != C / N) {
            cout << "N" << endl;
            return 0;
        }
    }
    
    cout << "S" << endl;
    return 0;
}
