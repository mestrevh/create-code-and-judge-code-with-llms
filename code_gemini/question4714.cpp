/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void formarRetangulo(int largura, int altura) {
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int largura, altura;
    cin >> largura >> altura;
    formarRetangulo(largura, altura);
    return 0;
}
