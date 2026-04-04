/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double weight, height;
    if (!(cin >> weight >> height)) return 0;

    if (height == 0) return 0;

    double imc = weight / (height * height);

    if (imc < 17.0) {
        cout << "muito abaixo do peso" << endl;
    } else if (imc < 18.5) {
        cout << "abaixo do peso" << endl;
    } else if (imc < 25.0) {
        cout << "peso normal" << endl;
    } else if (imc < 30.0) {
        cout << "acima do peso" << endl;
    } else if (imc < 35.0) {
        cout << "obesidade" << endl;
    } else if (imc < 40.0) {
        cout << "obesidade severa" << endl;
    } else {
        cout << "obesidade morbida" << endl;
    }

    return 0;
}
