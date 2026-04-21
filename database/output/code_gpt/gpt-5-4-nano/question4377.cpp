/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    char K;
    if (!(cin >> n >> K)) return 0;

    if (K == 'I') {
        long long totalStars = 2 * n - 1;
        for (long long r = 0; r < n; r++) {
            for (long long s = 0; s < r; s++) cout << ' ';
            for (long long j = 0; j < n - r; j++) {
                cout << '*';
                if (j + 1 < n - r) cout << ' ';
            }
            if (r < n - 1) cout << "\n";
        }
        if (n >= 2) {
            for (long long r = 0; r < n - 1; r++) {
                for (long long s = 0; s < n - 1 - r; s++) cout << ' ';
                long long stars = r + 1;
                for (long long j = 0; j < stars; j++) {
                    cout << '*';
                    if (j + 1 < stars) cout << ' ';
                }
                if (r < n - 2) cout << "\n";
            }
        }
    } else if (K == 'S') {
        for (long long r = 0; r < n; r++) {
            for (long long s = 0; s < 2 * r; s++) cout << ' ';
            long long stars = 2 * (n - r) - 1;
            for (long long j = 0; j < stars; j++) {
                cout << '*';
                if (j + 1 < stars) cout << ' ';
            }
            if (r < n - 1) cout << "\n";
        }
    } else if (K == 'T') {
        for (long long r = 0; r < n; r++) {
            for (long long s = 0; s < n - r - 1; s++) cout << ' ';
            for (long long j = 0; j < 2 * r + 1; j++) {
                cout << '*';
                if (j + 1 < 2 * r + 1) cout << ' ';
            }
            cout << "\n";
        }
        for (long long r = 0; r < n - 1; r++) {
            for (long long s = 0; s < r; s++) cout << ' ';
            long long stars = 2 * (n - r - 1) - 1;
            for (long long j = 0; j < stars; j++) {
                cout << '*';
                if (j + 1 < stars) cout << ' ';
            }
            if (r < n - 2) cout << "\n";
        }
    }

    return 0;
}