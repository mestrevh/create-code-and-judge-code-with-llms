/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long d, p, u, n;
    while (cin >> d >> p >> u >> n) {
        long long total = d + u + n;
        cout << total << "\n";
    }
    return 0;
}