/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long p;
    if (cin >> p) {
        long long v = p / 3;
        long long f = p % 3;
        cout << v << "\n" << f << "\n";
    }

    return 0;
}