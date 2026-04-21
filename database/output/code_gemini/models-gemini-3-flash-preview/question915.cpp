/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3, n4;
    while (cin >> n1 >> n2 >> n3 >> n4) {
        cout << "Informe a primeira nota do aluno:\n";
        cout << "Informe a segunda nota do aluno:\n";
        cout << "Informe a terceira nota do aluno:\n";
        cout << "Informe a quarta nota do aluno:\n";
        double media = (n1 + n2 + n3 + n4) / 4.0;
        cout << "Media: " << media << "\n";
    }

    return 0;
}