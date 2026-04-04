/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

bool isTriangular(int x) {
    if (x < 1) return false;
    long long val = 8LL * x + 1;
    long long s = (long long)round(sqrt((double)val));
    if (s * s != val) return false;
    return (s - 1) % 2 == 0;
}

bool isSquare(int x) {
    if (x < 1) return false;
    long long s = (long long)round(sqrt((double)x));
    return s * s == (long long)x;
}

bool isPentagonal(int x) {
    if (x < 1) return false;
    long long val = 24LL * x + 1;
    long long s = (long long)round(sqrt((double)val));
    if (s * s != val) return false;
    return (s + 1) % 6 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        if (!(cin >> n >> m)) break;
        int children = 0;
        int babies = 0;
        bool has_pentagonal = false;
        for (int i = 0; i < n * m; ++i) {
            int val;
            cin >> val;
            if (isTriangular(val)) {
                children++;
            } else if (isSquare(val)) {
                babies++;
            } else if (isPentagonal(val)) {
                has_pentagonal = true;
            }
        }
        cout << "Temos " << children << " crianças" << "\n";
        cout << "Temos " << babies << " bebês" << "\n";
        if (has_pentagonal) {
            cout << "Hoje o bebê vai chorar sozinho..." << "\n";
        } else {
            cout << "Oba! Kinho vai trabalhar hoje." << "\n";
        }
    }
    return 0;
}