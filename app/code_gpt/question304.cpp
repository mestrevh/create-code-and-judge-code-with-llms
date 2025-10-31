/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    int quantidade[7] = {0};

    for (int i = 0; i < 7; i++) {
        quantidade[i] = N / notas[i];
        N %= notas[i];
    }

    cout << N << endl;
    for (int i = 0; i < 7; i++) {
        cout << quantidade[i] << " nota(s) de R$ " << notas[i] << ",00" << endl;
    }

    return 0;
}
