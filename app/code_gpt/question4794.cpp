/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void contarSorvetes(int B, int K, int T, int &sorvetesB, int &sorvetesK) {
    sorvetesB = B / T;
    sorvetesK = K / T;
}

int main() {
    int B, K, T;
    cin >> B >> K >> T;

    int sorvetesB, sorvetesK;
    contarSorvetes(B, K, T, sorvetesB, sorvetesK);

    cout << "Badtz-Maru comeu " << sorvetesB << " sorvetes." << endl;
    cout << "Keroppi comeu " << sorvetesK << " sorvetes." << endl;

    return 0;
}
