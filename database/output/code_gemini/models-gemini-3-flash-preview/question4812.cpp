/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

float calcularMediaFinal(float notas[], int n) {
    sort(notas, notas + n);
    float soma = 0;
    for (int i = 2; i < n; ++i) {
        soma += notas[i];
    }
    return soma / (n - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 3) {
        float temp;
        for (int i = 0; i < n; ++i) cin >> temp;
        cout << "Numero de notas insuficiente." << endl;
    } else {
        float notas[105];
        for (int i = 0; i < n; ++i) {
            cin >> notas[i];
        }
        float media = calcularMediaFinal(notas, n);
        cout << fixed << setprecision(2) << media << endl;
    }

    return 0;
}