/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long m, n;
    if (cin >> m >> n) {
        if (m > n) {
            cout << "sem multiplos menores que " << n << endl;
        } else {
            // Since m and n are positive, (n / m) * m gives the largest multiple of m <= n.
            cout << (n / m) * m << endl;
        }
    }
    
    return 0;
}