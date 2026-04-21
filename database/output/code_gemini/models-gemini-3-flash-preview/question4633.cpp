/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long soma_idades = 0;
    int total_pessoas = 0;
    int idade_atual;

    while (cin >> idade_atual && idade_atual != 0) {
        soma_idades += idade_atual;
        total_pessoas++;
    }

    if (total_pessoas > 0) {
        int media = (int)(soma_idades / total_pessoas);

        cout << "media de idade da turma: " << media << "\n";

        if (media >= 0 && media <= 25) {
            cout << "jovem" << "\n";
        } else if (media >= 26 && media <= 60) {
            cout << "adulta" << "\n";
        } else if (media > 60) {
            cout << "idosa" << "\n";
        }
    }

    return 0;
}