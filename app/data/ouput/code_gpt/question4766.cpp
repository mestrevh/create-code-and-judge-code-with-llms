/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int num, soma = 0;
    while (true) {
        cin >> num;
        if (num == 0) break;
        if (num > 0) soma += num;
    }
    cout << "A soma dos valores eh: " << soma << endl;
    return 0;
}
