/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        if (n % 5 == 0) {
            cout << "Eh multiplo de 5" << endl;
        } else {
            cout << "Nao eh multiplo de 5" << endl;
        }
    }

    return 0;
}