/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> notas(n);
    for (int i = 0; i < n; ++i) {
        cin >> notas[i];
    }

    double soma = 0;
    for (double nota : notas) {
        soma += nota;
    }
    double media = soma / n;

    sort(notas.begin(), notas.end());
    double mediana;
    if (n % 2 == 0) {
        mediana = (notas[n / 2 - 1] + notas[n / 2]) / 2.0;
    } else {
        mediana = notas[n / 2];
    }

    map<double, int> freq;
    for (double nota : notas) {
        freq[nota]++;
    }

    int max_freq = 0;
    double moda;
    bool tem_moda = false;
    for (auto const& [nota, count] : freq) {
        if (count > max_freq) {
            max_freq = count;
            moda = nota;
            tem_moda = true;
        } else if (count == max_freq && tem_moda) {
            tem_moda = false;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Media: " << media << endl;
    cout << "Mediana: " << mediana << endl;
    if (tem_moda) {
        cout << "Moda: " << moda << endl;
    } else {
        cout << "Nao tem moda" << endl;
    }

    return 0;
}
