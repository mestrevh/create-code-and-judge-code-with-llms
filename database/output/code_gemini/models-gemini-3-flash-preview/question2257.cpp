/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int verificar_vizinho(long long n, int x) {
    int predecessor = x - 1;
    int sucessor = x + 1;
    do {
        int digito = (int)(n % 10);
        if (digito == predecessor || digito == sucessor) {
            return 1;
        }
        n /= 10;
    } while (n > 0);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    int x;
    if (cin >> n >> x) {
        if (verificar_vizinho(n, x)) {
            cout << "sim" << endl;
        } else {
            cout << "nao" << endl;
        }
    }
    return 0;
}