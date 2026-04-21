/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the layer of the current cell (i, j)
                // The value is 1 + the minimum distance to any of the four edges
                int val = min({i, j, n - 1 - i, n - 1 - j}) + 1;

                // Spacing format: Field width of 3 for each number,
                // and a single space separating the fields.
                if (j == 0) {
                    cout << setw(3) << val;
                } else {
                    cout << " " << setw(3) << val;
                }
            }
            // End of row
            cout << "\n";
        }
        // Blank line after each matrix
        cout << "\n";
    }

    return 0;
}