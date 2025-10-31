/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

bool isPerfect(int x) {
    int sum = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            sum += i;
        }
    }
    return sum == x;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int X;
        cin >> X;
        if (isPerfect(X)) {
            cout << X << " eh perfeito" << endl;
        } else {
            cout << X << " nao eh perfeito" << endl;
        }
    }
    return 0;
}
