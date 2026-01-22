/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, X;
    cin >> T;
    vector<int> V(T);
    for (int i = 0; i < T; ++i) cin >> V[i];
    cin >> X;

    int sum = 0, loops = 0, pos = 0;

    while (true) {
        sum += V[pos];
        if (sum == X) {
            cout << pos << " " << loops << endl;
            return 0;
        }
        if ((V[0] > 0 && sum > X) || (V[0] < 0 && sum < X)) {
            cout << "Esse numero deve estar errado..." << endl;
            return 0;
        }
        pos = (pos + 1) % T;
        if (pos == 0) loops++;
    }
}
