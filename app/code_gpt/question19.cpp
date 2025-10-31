/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double nota1, nota2, nota3, media;
    cin >> nota1 >> nota2 >> nota3;
    
    media = (nota1 + nota2 + nota3) / 3.0;

    if (media >= 7) {
        cout << "aprovado\n";
    } else if (media < 3) {
        cout << "reprovado\n";
    } else {
        cout << "prova final\n";
    }

    return 0;
}
