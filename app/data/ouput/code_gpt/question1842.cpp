/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double distancia(int Xa, int Ya, int Xb, int Yb) {
    return sqrt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb));
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int Xa, Ya, Xb, Yb;
        cin >> Xa >> Ya >> Xb >> Yb;
        cout << fixed << setprecision(2) << distancia(Xa, Ya, Xb, Yb) << endl;
    }
    return 0;
}
