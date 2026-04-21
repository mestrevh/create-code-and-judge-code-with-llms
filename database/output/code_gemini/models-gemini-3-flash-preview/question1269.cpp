/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int total_width = 2 * N + 1;
    for (int i = 0; i <= 2 * N; ++i) {
        int k = (i <= N) ? i : (2 * N - i);
        if (k == 0) {
            cout << string(total_width, '*') << "\n";
        } else {
            int stars_count = N - k + 1;
            int dots_count = 2 * k - 1;
            cout << string(stars_count, '*') << string(dots_count, '.') << string(stars_count, '*') << "\n";
        }
    }

    return 0;
}

