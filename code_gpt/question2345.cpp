/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void verificaRetangulo(int a, int b, int c, int d) {
    if ((a == c && b == d) || (a == d && b == c)) {
        cout << "formam um retangulo" << endl;
    } else {
        cout << "nao formam um retangulo" << endl;
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    verificaRetangulo(a, b, c, d);
    return 0;
}
