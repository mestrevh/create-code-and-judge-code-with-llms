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
    if (!(cin >> n)) return 0;

    int m = (int)n;
    int size = 2 * m + 1;

    for (int i = 0; i < size; i++) {
        int dist = abs(m - i);
        string line(size, '.');
        for (int j = 0; j < size; j++) {
            if (abs(j - m) + abs(i - m) == m) line[j] = '*';
            else if (abs(j - m) == dist && (i + j) % 2 == 1) line[j] = '*';
        }
        cout << line;
        if (i + 1 < size) cout << "\n";
    }
    return 0;
}