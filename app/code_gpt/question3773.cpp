/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct Aluno {
    string nome;
    double nota;
    int idade;
};

void trocar(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void ordenarNotas(Aluno alunos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (alunos[j].nota > alunos[j + 1].nota) {
                trocar(alunos[j].nota, alunos[j + 1].nota);
                swap(alunos[j], alunos[j + 1]);
            }
        }
    }
}

int main() {
    Aluno alunos[5];
    for (int i = 0; i < 5; i++) {
        getline(cin, alunos[i].nome);
        cin >> alunos[i].nota >> alunos[i].idade;
        cin.ignore();
    }
    ordenarNotas(alunos, 5);
    for (int i = 0; i < 5; i++) {
        cout << alunos[i].nome << " " << fixed << setprecision(2) << alunos[i].nota << " " << alunos[i].idade << endl;
    }
    return 0;
}
