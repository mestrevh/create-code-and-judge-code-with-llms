/*
Código criado pelo models/gemini-3.1-pro-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, a, b;
    if (cin >> m >> a >> b) {
        int c = m - (a + b);
        cout << max({a, b, c}) << "\n";
    }

    return 0;
}