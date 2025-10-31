/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int codigo;
    float nota1, nota2, nota3;

    while (true) {
        cout << "Informe o codigo do aluno: (0 para encerrar o programa)" << endl;
        cin >> codigo;
        if (codigo == 0) break;

        cout << "Informe a primeira nota do aluno:" << endl;
        cin >> nota1;
        cout << "Informe a segunda nota do aluno:" << endl;
        cin >> nota2;
        cout << "Informe a terceira nota do aluno:" << endl;
        cin >> nota3;

        float media = (nota1 + nota2 + nota3) / 3;
        cout << "Media do aluno: " << media << endl;
    }
    return 0;
}
