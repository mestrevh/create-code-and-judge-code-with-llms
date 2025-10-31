/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long n0, n;
    cin >> n0 >> n;
    long long count = (n - n0) / 2 + 1;
    long long sum = count * (n0 + n) / 2;
    cout << sum << endl;
    return 0;
}
