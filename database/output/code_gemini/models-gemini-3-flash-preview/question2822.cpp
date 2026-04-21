/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sex;
    double h;

    cout << "Digite o sexo: (0 - M e 1 - F)" << endl;
    if (!(cin >> sex)) return 0;
    
    cout << "Digite a altura em metros:" << endl;
    if (!(cin >> h)) return 0;

    if (sex != 0 && sex != 1) {
        cout << "O sexo informado e invalido." << endl;
    } else if (h <= 0) {
        cout << "Altura invalida" << endl;
    } else {
        double weight;
        if (sex == 0) {
            weight = (72.7 * h) - 58.0;
        } else {
            weight = (62.1 * h) - 44.7;
        }
        cout << fixed << setprecision(1) << "Peso ideal: " << weight << " kg" << endl;
    }

    return 0;
}