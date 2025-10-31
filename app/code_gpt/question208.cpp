/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool podeOrganizar(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0 && (n / i) > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    long long N;
    cin >> N;
    cout << (podeOrganizar(N) ? 'S' : 'N') << endl;
    return 0;
}
