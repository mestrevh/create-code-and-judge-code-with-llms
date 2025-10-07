/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calcularVodka(int X, int T) {
    double V = X;
    double n = X;
    
    for (int i = 1; i < T; ++i) {
        n *= (i % 2 == 0 ? X * X : 1) / (2 * i + 1);
        V += (i % 2 == 0 ? n : -n);
    }
    
    return V;
}

int main() {
    int X, T;
    cin >> X >> T;
    
    double resultado = calcularVodka(X, T);
    cout << fixed << setprecision(3) << fabs(resultado) << endl;
    
    return 0;
}
