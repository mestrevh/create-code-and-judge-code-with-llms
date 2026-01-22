/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float primeiro_angulo, segundo_angulo, terceiro_angulo;
    cin >> primeiro_angulo >> segundo_angulo;
    terceiro_angulo = 180 - (primeiro_angulo + segundo_angulo);
    cout << terceiro_angulo << endl;
    return 0;
}
