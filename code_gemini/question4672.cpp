/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int idade;
};

int main() {
    int n;
    cin >> n;
    vector<Aluno> alunos(n);
    for (int i = 0; i < n; i++) {
        cin >> alunos[i].nome >> alunos[i].idade;
    }
    for (int i = 0; i < n; i++) {
        if (alunos[i].idade <= 14) {
            cout << alunos[i].nome << endl;
            cout << alunos[i].idade << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        if (alunos[i].idade > 14) {
            cout << alunos[i].nome << endl;
            cout << alunos[i].idade << endl;
        }
    }
    return 0;
}
