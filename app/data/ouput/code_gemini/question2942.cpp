/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix& a, const Matrix& b, int n) {
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

Matrix power(Matrix base, int exp, int n) {
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base, n);
        }
        base = multiply(base, base, n);
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Matrix a(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int k;
    cin >> k;

    string p;
    cin >> p;

    Matrix final_matrix = power(a, k, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << final_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    long long s = 0;
    long long d = 0;
    for (int i = 0; i < n; ++i) {
        d += final_matrix[i][i];
        for (int j = 0; j < n; ++j) {
            s += final_matrix[i][j];
        }
    }

    int r = s % 14;

    cout << "Ru" << r;
    int total_minutes;
    if (d % 2 != 0) {
        cout << "e30?";
        total_minutes = r * 60 + 30;
    } else {
        cout << "?";
        total_minutes = r * 60;
    }

    if (total_minutes >= 720) {
        cout << " Aff.. Nem vai dar tempo de cochilar antes da aula de " << p << ".";
    } else if (total_minutes < 630) {
        cout << " Eita, cedo demais..";
    } else {
        cout << " Ainda bem, vai dar tempo de cochilar antes da aula de " << p << ".";
    }
    cout << "\n";

    return 0;
}
