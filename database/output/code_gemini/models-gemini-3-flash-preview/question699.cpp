/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ano_inicial, intervalo;
    if (cin >> ano_inicial >> intervalo) {
        cout << ano_inicial + intervalo << " " 
             << ano_inicial + 2 * intervalo << " " 
             << ano_inicial + 3 * intervalo << endl;
    }

    return 0;
}