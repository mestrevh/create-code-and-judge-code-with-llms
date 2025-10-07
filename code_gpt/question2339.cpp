/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "a: " << a << " b: " << b << endl;
    troca(&a, &b);
    cout << "a: " << a << " b: " << b << endl;
    return 0;
}
