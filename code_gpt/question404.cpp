/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

string ClassificaAluno(double media, int faltas) {
    if (faltas > 10) {
        return "REPROVADO POR FALTAS";
    } else if (media >= 9.5) {
        return "APROVADO COM LOUVOR";
    } else if (media >= 7) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    double media;
    int faltas;
    cin >> media >> faltas;
    cout << ClassificaAluno(media, faltas) << endl;
    return 0;
}
