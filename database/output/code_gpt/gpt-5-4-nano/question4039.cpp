/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    long long k;
    cin >> k;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    long long totalOnes = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            grid[i][j] = x;
            totalOnes += x;
        }
    }

    if (totalOnes != k) {
        cout << "Defesa invalida!";
        return 0;
    }

    long long attempts = 2 * k;
    vector<vector<char>> hit(n, vector<char>(n, 0));
    for (long long t = 0; t < attempts; t++) {
        long long x, y;
        cin >> x >> y;
        if (x < 0 || x >= n || y < 0 || y >= n) {
            cout << "Ataque invalido!";
            return 0;
        }
        if (grid[(int)x][(int)y] == 1) hit[(int)x][(int)y] = 1;
    }

    long long destroyed = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && hit[i][j]) destroyed++;
        }
    }

    if (destroyed == k) cout << "Ataque venceu!";
    else cout << "Defesa venceu!";

    return 0;
}