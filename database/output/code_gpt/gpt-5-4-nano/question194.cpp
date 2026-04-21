/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    const int MAXC = 101;
    vector<vector<int>> grid(MAXC, vector<int>(MAXC, 0));

    for (int i = 0; i < N; i++) {
        int Xi, Xf, Yi, Yf;
        cin >> Xi >> Xf >> Yi >> Yf;
        for (int x = Xi; x <= Xf; x++) {
            for (int y = Yi; y <= Yf; y++) {
                grid[x][y] = 1;
            }
        }
    }

    long long area = 0;
    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            if (grid[x][y]) area++;
        }
    }

    cout << area << "\n";
    return 0;
}