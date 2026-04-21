/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int processar(int n, int original) {
    if (n < 10) {
        if (n % 2 != 0) {
            return original - 3;
        } else {
            return original - 4;
        }
    }
    return processar(n / 10, original);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        cout << processar(n, n) << endl;
    }

    return 0;
}