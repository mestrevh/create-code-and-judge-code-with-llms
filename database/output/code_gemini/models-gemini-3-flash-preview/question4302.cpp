/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    while (cin >> x >> y) {
        long long resX = 2 * x;
        long long resY = 2 * y;

        cout << "X = " << hex << uppercase << resX << "\n";
        cout << "Y = " << hex << uppercase << resY << "\n";
    }

    return 0;
}