/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

float maior_numero(float a, float b) {
    if (a > b) return a;
    else if (b > a) return b;
    else {
        cout << "São iguais" << endl;
        return 0;
    }
}

int main() {
    float a, b;
    cin >> a >> b;
    float resultado = maior_numero(a, b);
    if (resultado != 0) cout << resultado << endl;
    return 0;
}
