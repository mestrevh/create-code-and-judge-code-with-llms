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

    double mass, height;
    if (cin >> mass >> height) {
        double imc = mass / (height * height);
        cout << fixed << setprecision(2) << imc << endl;
    }

    return 0;
}