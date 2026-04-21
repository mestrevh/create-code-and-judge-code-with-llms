/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p, m, g;
    while (cin >> p >> m >> g) {
        long long total = (p * 10) + (m * 12) + (g * 15);
        cout << "Total= R$ " << total << "\n";
    }

    return 0;
}