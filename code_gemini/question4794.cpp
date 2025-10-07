/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int sorvetesComidos(int tempoTotal, int tempoPorSorvete) {
    return tempoTotal / tempoPorSorvete;
}

int main() {
    int b, k, t;
    cin >> b >> k >> t;

    cout << "Badtz-Maru comeu " << sorvetesComidos(b, t) << " sorvetes." << endl;
    cout << "Keroppi comeu " << sorvetesComidos(k, t) << " sorvetes." << endl;

    return 0;
}
