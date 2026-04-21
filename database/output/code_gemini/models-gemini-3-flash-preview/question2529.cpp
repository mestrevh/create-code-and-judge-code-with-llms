/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (cin >> a >> b) {
        if (a > b) {
            cout << "A eh maior\n";
        } else if (b > a) {
            cout << "B eh maior\n";
        } else {
            cout << "iguais\n";
        }
    }

    return 0;
}