/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    long long total_insensitivity = 0;
    for (int i = 0; i < n; ++i) {
        long long x1, y1, x2, y2;
        if (!(cin >> x1 >> y1 >> x2 >> y2)) {
            break;
        }
        long long dx = x1 - x2;
        long long dy = y1 - y2;
        total_insensitivity += (dx * dx + dy * dy);
    }

    cout << total_insensitivity << "\n";

    return 0;
}