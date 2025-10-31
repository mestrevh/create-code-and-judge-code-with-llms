/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

void sequencia_aritmetica(int inicio, int razao, int termos) {
    for (int i = 0; i < termos; ++i) {
        cout << inicio + i * razao << endl;
    }
}

int main() {
    int inicio, razao, termos;
    cin >> inicio >> razao >> termos;
    sequencia_aritmetica(inicio, razao, termos);
    return 0;
}
