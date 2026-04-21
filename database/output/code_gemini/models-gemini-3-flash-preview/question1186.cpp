/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    if (!(cin >> R >> C)) {
        return 0;
    }

    if (R <= 0 || C <= 0 || R != C) {
        cout << "erro" << endl;
        return 0;
    }

    vector<long long> maxRows(R, std::numeric_limits<long long>::min());
    vector<long long> maxCols(C, std::numeric_limits<long long>::min());
    long long maxAll = std::numeric_limits<long long>::min();
    long long sumPosMain = 0;
    long long diffSec = 0;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            long long val;
            if (!(cin >> val)) break;
            
            if (val > maxRows[i]) maxRows[i] = val;
            if (val > maxCols[j]) maxCols[j] = val;
            if (val > maxAll) maxAll = val;
            
            if (i == j && val > 0) {
                sumPosMain += val;
            }
            
            if (i + j == R - 1) {
                if (i == 0) {
                    diffSec = val;
                } else {
                    diffSec -= val;
                }
            }
        }
    }

    cout << "[";
    for (int i = 0; i < R; ++i) {
        cout << maxRows[i] << (i == R - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    cout << "[";
    for (int j = 0; j < C; ++j) {
        cout << maxCols[j] << (j == C - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    cout << maxAll << endl;
    cout << sumPosMain << endl;
    cout << diffSec << endl;

    return 0;
}