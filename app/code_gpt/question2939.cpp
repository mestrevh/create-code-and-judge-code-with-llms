/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X, A, B, C;
    cin >> X >> A >> B >> C;
    
    int combate = (A + B - C) / 2;
    
    if (combate > X) {
        cout << "O Pokemon pode ser derrotado!" << endl;
    } else {
        cout << "Melhor nao arriscar" << endl;
    }
    
    return 0;
}
