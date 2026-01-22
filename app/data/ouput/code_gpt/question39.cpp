/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    double n1, n2, n3, media;
    cin >> n1 >> n2 >> n3;
    media = (n1 + n2 + n3) / 3.0;
    
    if (media >= 7.0) {
        cout << "aprovado" << endl;
    } else if (media < 3.0) {
        cout << "reprovado" << endl;
    } else {
        cout << "prova final" << endl;
    }
    
    return 0;
}
