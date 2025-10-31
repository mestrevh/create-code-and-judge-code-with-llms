/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int entregas[7], diasCumpridos = 0, soma = 0;
    for (int i = 0; i < 7; i++) {
        cin >> entregas[i];
        soma += entregas[i];
        if (entregas[i] >= 100) diasCumpridos++;
    }
    cout << diasCumpridos << endl;
    cout << soma / 7 << endl;
    return 0;
}
