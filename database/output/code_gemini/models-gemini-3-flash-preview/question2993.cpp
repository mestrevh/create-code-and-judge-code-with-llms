/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, n;
    if (!(cin >> x >> n)) return 0;

    long long count = (n - 1) / x;

    cout << "O numero " << x << " tem " << count << " multiplos menores que " << n << "." << endl;

    return 0;
}