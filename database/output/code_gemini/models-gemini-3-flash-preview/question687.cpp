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
    if (!(cin >> n)) return 0;

    // N is up to 25, so a 26x26 matrix is sufficient.
    // long long handles values easily as max value is 25C12 = 5,200,300.
    long long triangle[26][26];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            if (j > 0) {
                cout << " ";
            }
            cout << triangle[i][j];
        }
        cout << "\n";
    }

    return 0;
}