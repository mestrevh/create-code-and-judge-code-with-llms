/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double livros, alunos;
    while (cout << "Digite a quantidade de livros:\n" && cin >> livros) {
        cout << "Digite a quantidade de alunos:\n";
        if (!(cin >> alunos)) break;

        double ratio = alunos / livros;

        cout << "Numero de alunos por livro: " << ratio << ". Conceito ";

        if (ratio <= 8.0) {
            cout << "A";
        } else if (ratio <= 12.0) {
            cout << "B";
        } else if (ratio <= 18.0) {
            cout << "C";
        } else {
            cout << "D";
        }

        cout << " no MEC." << endl;
    }

    return 0;
}