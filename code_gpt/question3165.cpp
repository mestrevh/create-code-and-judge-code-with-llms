/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool verificaTriangulo(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << verificaTriangulo(a, b, c) << endl;
    return 0;
}
