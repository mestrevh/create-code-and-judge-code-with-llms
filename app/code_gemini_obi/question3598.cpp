/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = a - b;
    int y = b - c;
    int resposta = max(x, y);
    cout << resposta << endl;
    return 0;
}
