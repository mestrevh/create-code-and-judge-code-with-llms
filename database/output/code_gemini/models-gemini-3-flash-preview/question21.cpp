/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    if (n % 2 == 0) {
        n++;
    }

    for (long long i = n; i <= m; i += 2) {
        cout << i << "\n";
    }

    return 0;
}