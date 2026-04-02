/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> obstacles(n);
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> obstacles[i];
        if (obstacles[i] > max_val) {
            max_val = obstacles[i];
        }
    }

    vector<char> has_obstacle(max_val + 1, 0);
    for (int x : obstacles) {
        if (x <= max_val) {
            has_obstacle[x] = 1;
        }
    }

    for (int f = 1; ; ++f) {
        bool possible = true;
        for (int pos = f; pos <= max_val; pos += f) {
            if (has_obstacle[pos]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << f << endl;
            break;
        }
    }

    return 0;
}