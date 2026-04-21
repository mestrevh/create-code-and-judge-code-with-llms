/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

void sequencia_aritmetica(long long inicio, long long razao, int termos) {
    for (int i = 0; i < termos; ++i) {
        cout << inicio + (long long)i * razao << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long inicio, razao;
    int termos;

    if (cin >> inicio >> razao >> termos) {
        sequencia_aritmetica(inicio, razao, termos);
    }

    return 0;
}