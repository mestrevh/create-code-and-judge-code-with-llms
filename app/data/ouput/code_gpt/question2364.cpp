/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

long long f(int x, long long M) {
    if (x == 0) return 0;
    if (x == 1) return M;
    return (x % 2 == 0 ? x + f(x - 1, M) : M + f(x - 1, M));
}

int main() {
    long long M;
    cin >> M;
    int x = 1;
    while (f(x, M) < 10000000) {
        x++;
    }
    cout << x << " pessoas precisam assistir ao jogo." << endl;
    return 0;
}
