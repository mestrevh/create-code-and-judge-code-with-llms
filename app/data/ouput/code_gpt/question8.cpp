/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        double t = 0, x = 0, a = 0, b = 0, c = 0, d = 0, y = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int value = i * m + j + 1;
                t += value;
                if (j >= m - i - 1) x += value;
                if (j == 0) a += value;
                if (j == m - 1) b += value;
                if (i == 0) c += value;
                if (i == n - 1) d += value;
                if (i + j == n - 1) y += value;
            }
        }

        double result = (t - (x + y) + (a * b) - (c * d)) / (n * m);
        cout << fixed << setprecision(2) << result << endl;
    }

    return 0;
}
