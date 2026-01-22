/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double nota1, nota2, nota3, nota4, media;
    
    cout << "Informe a primeira nota do aluno:" << endl;
    cin >> nota1;
    cout << "Informe a segunda nota do aluno:" << endl;
    cin >> nota2;
    cout << "Informe a terceira nota do aluno:" << endl;
    cin >> nota3;
    cout << "Informe a quarta nota do aluno:" << endl;
    cin >> nota4;
    
    media = (nota1 + nota2 + nota3 + nota4) / 4;
    
    cout << "Media: " << fixed << setprecision(3) << media << endl;
    
    return 0;
}
