/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double nota;
    if (cin >> nota) {
        if (nota > 7.0) {
            cout << "bolinha verde" << endl;
        } else if (nota >= 5.0) {
            cout << "bolinha amarela" << endl;
        } else {
            cout << "bolinha vermelha" << endl;
        }
    }

    return 0;
}