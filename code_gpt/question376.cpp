/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int livros, alunos;
    cin >> livros >> alunos;
    int alunosPorLivro = alunos / livros;
    if (alunosPorLivro <= 8) {
        cout << "A" << endl;
    } else if (alunosPorLivro <= 12) {
        cout << "B" << endl;
    } else if (alunosPorLivro <= 18) {
        cout << "C" << endl;
    } else {
        cout << "D" << endl;
    }
    return 0;
}
