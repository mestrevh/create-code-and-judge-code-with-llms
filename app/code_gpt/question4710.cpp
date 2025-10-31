/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void tabuada(float n1, float n2, float n3) {
    float media = (n1 + n2 + n3) / 3;
    if (media >= 6.0) {
        cout << "Aprovado" << endl;
    } else {
        cout << "Reprovado" << endl;
    }
}

int main() {
    float n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    tabuada(n1, n2, n3);
    return 0;
}
