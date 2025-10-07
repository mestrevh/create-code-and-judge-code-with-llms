/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> alunos(n);
    int soma = 0;

    for (int i = 0; i < n; ++i) {
        cin >> alunos[i];
        while (alunos[i] > 40) {
            cout << "O numero de alunos nao pode ser maior que 40" << endl;
            cin >> alunos[i];
        }
        soma += alunos[i];
    }

    double media = static_cast<double>(soma) / n;
    cout << round(media) << endl;

    return 0;
}
