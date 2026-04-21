/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long soma = 0;
    int n;

    while (cin >> n && n != 0) {
        if (n > 0) {
            soma += n;
        }
    }

    cout << "A soma dos valores eh: " << soma << endl;

    return 0;
}