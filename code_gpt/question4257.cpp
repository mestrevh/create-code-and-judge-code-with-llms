/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    float angulo1, angulo2;
    cout << "Digite o 1° ângulo:\n";
    cin >> angulo1;
    cout << "Digite o 2° ângulo:\n";
    cin >> angulo2;
    float angulo3 = 180 - (angulo1 + angulo2);
    cout << "O terceiro ângulo é: " << angulo3 << endl;
    return 0;
}
