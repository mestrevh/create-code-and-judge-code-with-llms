/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        long long d;
        if (!(cin >> d)) break;

        long long bestX = -1;
        int bestY = -1;
        int bestE = -1;

        for (int i = 1; i <= n; ++i) {
            long long k, b;
            cin >> k >> b;

            long long x = d + 100 + (k * 20) + b;
            long long diff = x - d;
            
            // Percentage increase: ceil((diff * 100) / d)
            // Using integer arithmetic to simulate ceil(a/b) for positive a, b: (a + b - 1) / b
            long long numerator = diff * 100;
            int y = (int)((numerator + d - 1) / d);

            cout << "ELEMENTO #" << i << "\n";
            cout << "DANO: " << x << "\n";
            cout << "AUMENTO: " << y << "%\n\n";

            if (x > bestX) {
                bestX = x;
                bestY = y;
                bestE = i;
            }
        }

        if (bestE != -1) {
            cout << "ELEMENTO ESCOLHIDO: #" << bestE << "\n";
            cout << "NOVO DANO DA ESPADA: " << bestX << "\n";
            cout << "AUMENTO: " << bestY << "%\n";
        }
    }

    return 0;
}