/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int F(int X, int Q, int N) {
    if (X >= N) {
        return X - N + (X * Q);
    } else {
        return F(X * Q, Q, N - X);
    }
}

int main() {
    int X, Q, N;
    cin >> X >> Q >> N;
    cout << F(X, Q, N) << endl;
    return 0;
}
