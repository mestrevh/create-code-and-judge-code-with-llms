/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double livros, alunos;
    cout << "Digite a quantidade de livros: ";
    if (!(cin >> livros)) return 0;
    cout << "Digite a quantidade de alunos: ";
    if (!(cin >> alunos)) return 0;

    double alunosPorLivro = alunos / livros;

    char conceito;
    if (alunosPorLivro <= 8.0) conceito = 'A';
    else if (alunosPorLivro <= 12.0) conceito = 'B';
    else if (alunosPorLivro <= 18.0) conceito = 'C';
    else conceito = 'D';

    cout << fixed << setprecision(10);
    cout << "Numero de alunos por livro: ";
    cout << alunosPorLivro;
    cout.unsetf(ios::floatfield);
    cout << " Conceito " << conceito << " no MEC.\n";

    return 0;
}