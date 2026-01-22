/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int countWays(int Q, int D) {
    if (Q == 0) return D <= 0 ? 1 : 0;
    int ways = 0;
    for (int i = 1; i <= 6; ++i) {
        ways += countWays(Q - 1, D - i);
    }
    return ways;
}

int main() {
    int Q, D;
    cin >> Q >> D;
    cout << countWays(Q, D) << endl;
    return 0;
}
