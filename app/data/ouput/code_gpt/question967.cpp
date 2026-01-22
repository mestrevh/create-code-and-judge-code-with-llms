/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void desenharArvore(int N) {
    for (int i = N; i > 0; i -= 2) {
        int espacos = (N - i) / 2;
        for (int j = 0; j < espacos; j++) cout << "-";
        for (int j = 0; j < i; j++) cout << "*";
        for (int j = 0; j < espacos; j++) cout << "-";
        cout << endl;
    }

    int tronco = (N % 2 == 0 ? N + 1 : N);
    for (int i = 0; i < 2; i++) { // tronco com 2 asteriscos de altura
        int espacos = (tronco - 1) / 2;
        for (int j = 0; j < espacos; j++) cout << "-";
        cout << "*" << endl;
    }

    cout << endl;
}

int main() {
    int N;
    while (cin >> N) {
        desenharArvore(N);
    }
    return 0;
}
