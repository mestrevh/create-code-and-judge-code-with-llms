/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int subtrair(int a, int b) {
    return a - b;
}

int main() {
    int a, b;
    cin >> a >> b;
    int resultado = subtrair(a, b);
    cout << resultado << endl;
    return 0;
}
