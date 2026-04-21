/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while (cin >> x && x != 0) {
        long long a = (x + 1) / 2;
        long long b = (x - 1) / 2;
        cout << a * a << " - " << b * b << "\n";
    }

    return 0;
}