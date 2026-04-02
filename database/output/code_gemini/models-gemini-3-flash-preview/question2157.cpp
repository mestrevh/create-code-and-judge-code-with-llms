/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<long long>> mat;
    string line;
    
    while (getline(cin, line)) {
        size_t pos = line.find("acabou");
        if (pos != string::npos) {
            string prefix = line.substr(0, pos);
            stringstream ss(prefix);
            vector<long long> row;
            long long val;
            while (ss >> val) {
                row.push_back(val);
            }
            if (!row.empty()) {
                mat.push_back(row);
            }
            break;
        }
        
        stringstream ss(line);
        vector<long long> row;
        long long val;
        bool has_val = false;
        while (ss >> val) {
            row.push_back(val);
            has_val = true;
        }
        if (has_val) {
            mat.push_back(row);
        }
    }

    if (mat.empty()) {
        return 0;
    }

    int R = (int)mat.size();
    int C = (int)mat[0].size();
    bool square = true;

    for (int i = 0; i < R; ++i) {
        if ((int)mat[i].size() != C) {
            square = false;
            break;
        }
    }
    if (R != C) {
        square = false;
    }

    if (!square) {
        cout << "O determinante de uma matriz só existe para matrizes quadradas." << endl;
        return 0;
    }

    bool is_zero = false;

    // Check rows for all zeros or identical rows
    for (int i = 0; i < R; ++i) {
        bool all_zero = true;
        for (int j = 0; j < C; ++j) {
            if (mat[i][j] != 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) {
            is_zero = true;
            break;
        }
        for (int k = i + 1; k < R; ++k) {
            if (mat[i] == mat[k]) {
                is_zero = true;
                break;
            }
        }
        if (is_zero) break;
    }

    // Check columns for all zeros or identical columns
    if (!is_zero) {
        for (int j = 0; j < C; ++j) {
            bool all_zero = true;
            for (int i = 0; i < R; ++i) {
                if (mat[i][j] != 0) {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero) {
                is_zero = true;
                break;
            }
            for (int l = j + 1; l < C; ++l) {
                bool identical = true;
                for (int i = 0; i < R; ++i) {
                    if (mat[i][j] != mat[i][l]) {
                        identical = false;
                        break;
                    }
                }
                if (identical) {
                    is_zero = true;
                    break;
                }
            }
            if (is_zero) break;
        }
    }

    if (is_zero) {
        cout << "Determinante zero." << endl;
    } else {
        cout << "Determinante nao zero." << endl;
    }

    return 0;
}