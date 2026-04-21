/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (n == 1) {
            cout << "Bulbassauro" << endl;
        } else if (n == 2) {
            cout << "Charmander" << endl;
        } else if (n == 3) {
            cout << "Squirtle" << endl;
        }
    }

    return 0;
}