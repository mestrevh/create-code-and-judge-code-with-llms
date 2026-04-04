/*
Código criado pelo models/gemini-3-flash-preview
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
    } else if (media >= 7.0) {
        return "APROVADO";
    } else {
        return "REPROVADO";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double media;
    int faltas;

    if (cin >> media >> faltas) {
        cout << ClassificaAluno(media, faltas) << endl;
    }

    return 0;
}