/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long a, b, m;
        if (!(cin >> a >> b >> m)) break;

        // Reduz a e b para valores menores que m para evitar overflow na multiplicação.
        // Como m <= 10^9, (a % m) e (b % m) serão <= 10^9.
        // O produto (a % m) * (b % m) será no máximo 10^18, que cabe em um long long (max ~9.22e18).
        long long a_mod = a % m;
        long long b_mod = b % m;
        
        long long result = (a_mod * b_mod) % m;
        
        cout << result << "\n";
    }

    return 0;
}