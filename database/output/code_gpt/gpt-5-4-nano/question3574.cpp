/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isTriangular(int x) {
    long double d = 1.0L + 8.0L * x;
    long double s = sqrt(d);
    long long r = llround(s);
    if (r * r != (long long)(d + 0.5L)) {
        if ((r - 1) > 0 && (r - 1) * (r - 1) == (long long)(d + 0.5L)) r--;
        else return false;
    }
    return ((r - 1) % 2 == 0);
}

static bool isSquare(int x) {
    long double s = sqrt((long double)x);
    long long r = llround(s);
    return r * r == x;
}

static bool isPentagonal(int x) {
    long double d = 1.0L + 24.0L * x;
    long double s = sqrt(d);
    long long r = llround(s);
    if (r * r != (long long)(d + 0.5L)) {
        if ((r - 1) > 0 && (r - 1) * (r - 1) == (long long)(d + 0.5L)) r--;
        else return false;
    }
    return (1 + r) % 6 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    for (int _ = 0; _ < t; _++) {
        int N, M;
        cin >> N >> M;

        int children = 0, babies = 0;
        bool cry = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x;
                cin >> x;

                if (isTriangular(x)) {
                    children++;
                } else if (isSquare(x)) {
                    babies++;
                } else if (isPentagonal(x)) {
                    cry = true;
                } else {
                    if (isPentagonal(x)) cry = true;
                }
            }
        }

        cout << "Temos " << children << " crianças\n";
        cout << "Temos " << babies << " bebês\n";
        if (!cry) cout << "Hoje o bebê vai chorar sozinho...\n";
        else cout << "Oba! Kinho vai trabalhar hoje.\n";
    }

    return 0;
}