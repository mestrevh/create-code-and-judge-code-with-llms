/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        int d1 = n / 100;
        int d3 = n % 10;
        int d2 = (n - (d1 * 100 + d3)) / 10;

        cout << d1 << " " << d2 << " " << d3 << "\n";
    }

    return 0;
}