/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int count_divisors(int x) {
    int count = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            count += (i * i == x) ? 1 : 2;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int X;
        cin >> X;
        if (count_divisors(X) < 4) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
