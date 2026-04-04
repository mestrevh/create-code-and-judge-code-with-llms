/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double mass, height;
    if (!(cin >> mass >> height)) return 0;

    double imc_calc = mass / (height * height);
    int imc = (int)imc_calc;

    cout << "Digite a massa em kg e altura em m:" << "\n";
    cout << "IMC: " << imc << endl;

    return 0;
}

