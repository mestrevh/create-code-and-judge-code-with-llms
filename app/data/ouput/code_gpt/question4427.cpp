/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

double calcMedia(const vector<int>& notas) {
    double soma = 0;
    for (int nota : notas) {
        soma += nota;
    }
    return soma / notas.size();
}

double calcMediana(vector<int>& notas) {
    sort(notas.begin(), notas.end());
    int n = notas.size();
    return n % 2 == 0 ? (notas[n / 2 - 1] + notas[n / 2]) / 2.0 : notas[n / 2];
}

int calcModa(const vector<int>& notas) {
    map<int, int> freq;
    for (int nota : notas) {
        freq[nota]++;
    }
    int maxFreq = 0, moda = -1, count = 0;
    for (const auto& par : freq) {
        if (par.second > maxFreq) {
            maxFreq = par.second;
            moda = par.first;
            count = 1;
        } else if (par.second == maxFreq) {
            count++;
        }
    }
    return (count == 1) ? moda : -1; // retorne -1 se não houver moda
}

int main() {
    int N;
    cin >> N;
    vector<int> notas(N);
    for (int i = 0; i < N; ++i) {
        cin >> notas[i];
    }

    double media = calcMedia(notas);
    double mediana = calcMediana(notas);
    int moda = calcModa(notas);

    cout << fixed << setprecision(2);
    cout << "Media: " << media << endl;
    cout << "Mediana: " << mediana << endl;

    if (moda != -1) {
        cout << "Moda: " << moda << endl;
    } else {
        cout << "Nao tem moda" << endl;
    }

    return 0;
}
