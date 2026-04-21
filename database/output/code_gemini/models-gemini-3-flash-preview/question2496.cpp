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

    int rows, cols;
    if (!(cin >> rows >> cols)) {
        return 0;
    }

    if (rows <= 0 || cols <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> column_haunted(cols, false);
    long long total_sum = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int price;
            if (!(cin >> price)) break;

            if (!column_haunted[j]) {
                if (price == 0) {
                    column_haunted[j] = true;
                } else {
                    total_sum += price;
                }
            }
        }
    }

    cout << total_sum << endl;

    return 0;
}