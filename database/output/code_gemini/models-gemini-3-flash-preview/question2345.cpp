/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

void verificarRetangulo(int a, int b, int c, int d) {
    int lados[4] = {a, b, c, d};
    sort(lados, lados + 4);
    if (lados[0] == lados[1] && lados[2] == lados[3]) {
        cout << "formam um retangulo" << endl;
    } else {
        cout << "nao formam um retangulo" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c, d;
    if (cin >> a >> b >> c >> d) {
        verificarRetangulo(a, b, c, d);
    }
    
    return 0;
}