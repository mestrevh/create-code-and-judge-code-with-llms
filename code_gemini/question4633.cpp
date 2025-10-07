/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int idade;
    vector<int> idades;

    cin >> idade;
    while (idade != 0) {
        idades.push_back(idade);
        cin >> idade;
    }

    if (idades.empty()) {
        return 0;
    }

    double media = accumulate(idades.begin(), idades.end(), 0.0) / idades.size();
    int media_arredondada = round(media);

    cout << "media de idade da turma: " << media_arredondada << endl;

    if (media_arredondada >= 0 && media_arredondada <= 25) {
        cout << "jovem" << endl;
    } else if (media_arredondada >= 26 && media_arredondada <= 60) {
        cout << "adulta" << endl;
    } else {
        cout << "idosa" << endl;
    }

    return 0;
}
