/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int tempo = (Z * 60) / (Y - X);
    cout << tempo << " minutos" << endl;
    return 0;
}
