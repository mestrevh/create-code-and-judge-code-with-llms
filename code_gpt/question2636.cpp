/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int livros, alunos;
    cout << "Digite a quantidade de livros:\n";
    cin >> livros;
    cout << "Digite a quantidade de alunos:\n";
    cin >> alunos;

    double alunosPorLivro = static_cast<double>(alunos) / livros;
    string conceito;

    if (alunosPorLivro <= 8) conceito = "A";
    else if (alunosPorLivro <= 12) conceito = "B";
    else if (alunosPorLivro <= 18) conceito = "C";
    else conceito = "D";

    cout << fixed << setprecision(2);
    cout << "Numero de alunos por livro: " << alunosPorLivro << ". Conceito " << conceito << " no MEC.\n";

    return 0;
}
