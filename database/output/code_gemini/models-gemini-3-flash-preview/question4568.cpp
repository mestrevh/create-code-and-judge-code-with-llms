/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> matrix(9);
    long long total_sum = 0;
    int max_val;
    int diag_sum = 0;

    for (int i = 0; i < 9; ++i) {
        cin >> matrix[i];
        total_sum += matrix[i];
        if (i == 0) {
            max_val = matrix[i];
        } else {
            if (matrix[i] > max_val) {
                max_val = matrix[i];
            }
        }
        if (i == 0 || i == 4 || i == 8) {
            diag_sum += matrix[i];
        }
    }

    double average = static_cast<double>(total_sum) / 9.0;
    int delta = 0;
    if (max_val > 0) delta = 1;
    else if (max_val < 0) delta = -1;

    cout << fixed << setprecision(2) << average << " " << max_val << " " << delta << " " << diag_sum << endl;

    return 0;
}

