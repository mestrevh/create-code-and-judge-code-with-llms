/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int H, A;
    cin >> H >> A;
    
    int titanHeight = 5, soldierHeight = 0;
    
    while (titanHeight < 50) {
        titanHeight += H;
        if (titanHeight >= 50) {
            cout << "Comandante, a operacao falhou!" << endl;
            cout << "Altura alcancada pelo soldado: " << soldierHeight << endl;
            return 0;
        }
        soldierHeight += A;
    }
    
    cout << "Capturamos ele, comandante!" << endl;
    cout << "Altura alcancada pelo titã: " << titanHeight << endl;
    cout << "Altura alcancada pelo soldado: " << soldierHeight << endl;

    return 0;
}
