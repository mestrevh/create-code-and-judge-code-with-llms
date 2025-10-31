/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        swap(a %= b, b);
    }
    return a;
}

int main() {
    long long M, N;
    cin >> M >> N;
    long long result = (gcd(M, N) - 1);
    cout << result << endl;
    return 0;
}
