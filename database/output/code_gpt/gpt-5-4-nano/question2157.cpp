/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool equalRows(const vector<double>& a, const vector<double>& b) {
    if (a.size() != b.size()) return false;
    const double eps = 1e-9;
    for (size_t i = 0; i < a.size(); i++) {
        if (fabs(a[i] - b[i]) > eps) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<double>> mat;
    string first;
    while (cin >> first) {
        if (first == "acabou") break;
        double x;
        try {
            x = stod(first);
        } catch (...) {
            continue;
        }
        vector<double> row;
        row.push_back(x);

        string s;
        while (true) {
            streampos pos = cin.tellg();
            if (!(cin >> s)) {
                mat.push_back(row);
                break;
            }
            if (s == "acabou") {
                mat.push_back(row);
                return 0;
            }
            try {
                double v = stod(s);
                row.push_back(v);
            } catch (...) {
                continue;
            }
        }
        mat.push_back(row);
        if (cin.eof()) break;
    }

    if (mat.empty()) return 0;

    size_t n = mat.size();
    size_t m = mat[0].size();
    bool rectangular = true;
    for (size_t i = 1; i < n; i++) {
        if (mat[i].size() != m) {
            rectangular = false;
            break;
        }
    }

    if (!rectangular || n != m) {
        cout << "O determinante de uma matriz só existe para matrizes quadradas.\n";
        return 0;
    }

    const double eps = 1e-9;

    bool detZero = false;

    for (size_t i = 0; i < n && !detZero; i++) {
        bool allZero = true;
        for (size_t j = 0; j < m; j++) {
            if (fabs(mat[i][j]) > eps) {
                allZero = false;
                break;
            }
        }
        if (allZero) detZero = true;
    }

    for (size_t j = 0; j < m && !detZero; j++) {
        bool allZero = true;
        for (size_t i = 0; i < n; i++) {
            if (fabs(mat[i][j]) > eps) {
                allZero = false;
                break;
            }
        }
        if (allZero) detZero = true;
    }

    for (size_t i = 0; i < n && !detZero; i++) {
        for (size_t k = i + 1; k < n && !detZero; k++) {
            if (equalRows(mat[i], mat[k])) detZero = true;
        }
    }

    vector<vector<double>> trans(m, vector<double>(n, 0.0));
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            trans[j][i] = mat[i][j];

    for (size_t j1 = 0; j1 < m && !detZero; j1++) {
        for (size_t j2 = j1 + 1; j2 < m && !detZero; j2++) {
            if (equalRows(trans[j1], trans[j2])) detZero = true;
        }
    }

    if (detZero) cout << "Determinante zero.\n";
    else cout << "Determinante não zero.\n";
    return 0;
}