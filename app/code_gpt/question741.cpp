/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N >= 0) {
        double S = 0.0;
        for (int i = 0; i <= N; ++i) {
            S += static_cast<double>(i) / (i + 1);
        }
        cout << S << endl;
    } else {
        N = -N;
        double P = 1.0;
        for (int i = 1; i <= N; ++i) {
            P *= static_cast<double>(i + 2) / i;
        }
        cout << P << endl;
    }

    return 0;
}
