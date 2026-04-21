/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string dummy;
    getline(cin, dummy);

    for (int i = 0; i < n; ++i) {
        string name;
        if (!getline(cin, name)) break;

        double w, h;
        if (!(cin >> w >> h)) break;
        getline(cin, dummy);

        double imc = w / (h * h);

        cout << name << ":" << "\n";

        if (imc < 18.5) {
            cout << "Baixo peso" << "\n";
        } else if (imc < 25.0) {
            cout << "Peso normal" << "\n";
        } else if (imc < 30.0) {
            cout << "Sobrepeso" << "\n";
        } else if (imc < 35.0) {
            cout << "Obesidade grau I" << "\n";
        } else if (imc < 40.0) {
            cout << "Obesidade grau II" << "\n";
        } else {
            cout << "Obesidade grau III" << "\n";
        }

        if (i < n - 1) {
            cout << "\n";
        }
    }

    return 0;
}