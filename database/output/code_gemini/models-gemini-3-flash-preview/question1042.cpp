/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long idade;
    if (cin >> idade) {
        long long segundos = idade * 365LL * 24LL * 60LL * 60LL;
        cout << segundos << "\n";
    }

    return 0;
}