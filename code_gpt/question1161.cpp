/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int max(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}

int main() {
    int A, L, P, H;
    cin >> A >> L >> P >> H;
    cout << max(max(A * H, L * H), P * H) << endl;
    return 0;
}
