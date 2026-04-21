/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> mat[i])) break;
    }

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            char c = mat[i][j];
            if (c >= 'a' && c <= 'z') {
                c = (char)((c - 'a' + 2) % 26 + 'a');
            }
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}