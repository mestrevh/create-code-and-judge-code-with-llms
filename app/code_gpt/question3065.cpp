/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double largura, altura;
    cin >> largura >> altura;
    double diagonal = sqrt(largura * largura + altura * altura);
    cout << diagonal << endl;
    return 0;
}
