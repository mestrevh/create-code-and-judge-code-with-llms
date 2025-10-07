/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int parOuImpar(int x) {
    return (x % 2 == 0) ? 1 : -1;
}

int main() {
    int x;
    cin >> x;
    cout << parOuImpar(x) << endl;
    return 0;
}
