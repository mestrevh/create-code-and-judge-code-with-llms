/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    cout << "Digite o valor inteiro:" << endl;

    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < 7; i++) {
        int quantidade = N / notas[i];
        N %= notas[i];
        if (notas[i] == 1)
            cout << quantidade << " moeda(s) de R$ " << notas[i] << ",00" << endl;
        else
            cout << quantidade << " nota(s) de R$ " << notas[i] << ",00" << endl;
    }

    return 0;
}
