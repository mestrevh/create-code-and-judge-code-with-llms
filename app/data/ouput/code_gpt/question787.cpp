/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int fastExp(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int half = fastExp(a, n / 2);
        return half * half;
    } else {
        return a * fastExp(a, n - 1);
    }
}

int main() {
    int a, n;
    cin >> a >> n;
    cout << fastExp(a, n) << endl;
    return 0;
}
