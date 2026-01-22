/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> matrix(n, vector<string>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            getline(cin, matrix[i][j]);
        }
    }

    string word;
    while (getline(cin, word)) {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j].find(word) != string::npos) {
                    cout << "(" << i << "," << j << ")" << endl;
                    found = true;
                }
            }
        }
        if (found) cout << endl;
    }
    return 0;
}
