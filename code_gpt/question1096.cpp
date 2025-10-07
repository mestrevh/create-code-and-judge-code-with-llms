/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    double S = 0.0;
    for (int i = 1; i <= N; i++) {
        S += pow(2, i) * (3.14 / (i + 1));
    }
    cout << fixed << setprecision(2) << "Valor de S : " << S << endl;
    return 0;
}
