/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int obter_maximo(int a, int b) {
    bool a_maior = (a > b);
    bool b_maior_igual = (b >= a);
    return (a * a_maior) + (b * b_maior_igual);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while (cin >> a >> b) {
        cout << obter_maximo(a, b) << "\n";
    }

    return 0;
}