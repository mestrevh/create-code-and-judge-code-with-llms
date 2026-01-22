/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int rickception(int n, int t) {
    if (t == 0) return n;
    if (t == 1) return n + 3;
    return rickception(n + (t % 2 == 0 ? 3 : n % 5), t - 1);
}

int main() {
    int n, t;
    cin >> n >> t;
    cout << rickception(n, t) << endl;
    return 0;
}
