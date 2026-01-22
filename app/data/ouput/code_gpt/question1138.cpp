/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    long long n = A;
    while (n <= 1000000000) {
        if (n % A == 0 && B % n != 0 && C % n == 0 && D % n != 0) {
            cout << n << endl;
            return 0;
        }
        n += A;
    }
    cout << -1 << endl;
    return 0;
}
