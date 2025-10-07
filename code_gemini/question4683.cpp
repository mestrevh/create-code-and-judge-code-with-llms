/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int start = -1, end = -1, symbols = 0;
    for (int j = 0; j < m; ++j) {
        bool white_pixel = false;
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] == 1) {
                white_pixel = true;
                break;
            }
        }

        if (white_pixel) {
            if (start == -1) {
                start = j;
            }
            end = j;
        } else {
            if (start != -1) {
                int prev_end = (symbols == 0) ? 0 : (start + prev_end + 1) / 2;
                int next_start = (end == m -1) ? m-1: (end + j) / 2;


                for (int i = 0; i < n; ++i) {
                    for (int k = prev_end; k <= next_start; ++k) {
                        cout << matrix[i][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl << endl;
                
                prev_end = next_start;
                start = -1;
                symbols++;
            }
        }
    }

    cout << "Foram encontrados " << symbols << " simbolos!" << endl;

    return 0;
}
