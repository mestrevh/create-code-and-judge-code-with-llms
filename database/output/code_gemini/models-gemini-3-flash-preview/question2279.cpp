/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int verificar_vizinho(long long n, int x) {
    int d = (int)(n % 10);
    if (d == x - 1 || d == x + 1) {
        return 1;
    }
    if (n < 10) {
        return 0;
    }
    return verificar_vizinho(n / 10, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    int x;
    if (cin >> n >> x) {
        if (verificar_vizinho(n, x)) {
            cout << "sim\n";
        } else {
            cout << "nao\n";
        }
    }

    return 0;
}