/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, b, soma = 0;
    cin >> a >> b;
    if (a > b) swap(a, b);
    for (int i = a + 1; i < b; i++) {
        if (1000 % i == 0 && i % 4 == 0) {
            soma += i;
        }
    }
    cout << soma << endl;
    return 0;
}
