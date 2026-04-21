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
    if (n <= 0) return 0;

    vector<int> mat(n * n);

    int r_min = 0, r_max = n - 1;
    int c_min = 0, c_max = n - 1;
    int count = 0;
    int total = n * n;

    while (count < total) {
        // Down
        for (int i = r_min; i <= r_max && count < total; ++i) {
            cin >> mat[i * n + c_min];
            count++;
        }
        c_min++;

        // Right
        for (int j = c_min; j <= c_max && count < total; ++j) {
            cin >> mat[r_max * n + j];
            count++;
        }
        r_max--;

        // Up
        for (int i = r_max; i >= r_min && count < total; --i) {
            cin >> mat[i * n + c_max];
            count++;
        }
        c_max--;

        // Left
        for (int j = c_max; j >= c_min && count < total; --j) {
            cin >> mat[r_min * n + j];
            count++;
        }
        r_min++;
    }

    for (int i = 0; i < total; ++i) {
        cout << mat[i] << "\n";
    }

    return 0;
}