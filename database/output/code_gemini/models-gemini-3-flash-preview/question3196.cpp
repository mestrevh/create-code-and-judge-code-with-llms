/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long preco;
    if (!(cin >> preco)) return 0;

    int notas[] = {100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 7; ++i) {
        cout << preco / notas[i] << "\n";
        preco %= notas[i];
    }

    return 0;
}