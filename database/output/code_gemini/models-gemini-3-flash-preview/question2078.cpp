/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) break;
    }

    vector<bool> vis(n, false);
    int current_pos = 0;
    long long total_coins = a[current_pos];
    vis[current_pos] = true;

    char op;
    long long steps;
    while (cin >> op >> steps) {
        if (op == '+') {
            current_pos = (int)((current_pos + (steps % (long long)n)) % (long long)n);
        } else if (op == '-') {
            current_pos = (int)((current_pos - (int)(steps % (long long)n) + n) % n);
        }

        if (current_pos >= 0 && current_pos < n) {
            if (!vis[current_pos]) {
                total_coins += a[current_pos];
                vis[current_pos] = true;
            }
        }
    }

    cout << total_coins << endl;

    return 0;
}