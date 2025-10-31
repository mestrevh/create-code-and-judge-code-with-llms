/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int multiplicacao(int a, int b) {
    if (b == 0) return 0;
    return a + multiplicacao(a, b - 1);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << multiplicacao(a, b) << endl;
    return 0;
}
