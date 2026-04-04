/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef __int128_t int128;

string int128ToString(int128 n) {
    if (n == 0) return "0";
    bool neg = false;
    if (n < 0) {
        neg = true;
        n = -n;
    }
    string s = "";
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

int128 stringToInt128(string s) {
    int128 res = 0;
    bool neg = false;
    int i = 0;
    if (s.empty()) return 0;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }
    for (; i < (int)s.length(); i++) {
        res = res * 10 + (s[i] - '0');
    }
    return neg ? -res : res;
}

struct Matrix {
    int n;
    vector<vector<int128>> mat;
    Matrix(int n) : n(n), mat(n, vector<int128>(n, 0)) {}
};

Matrix multiply(const Matrix& a, const Matrix& b) {
    Matrix res(a.n);
    for (int i = 0; i < a.n; i++) {
        for (int k = 0; k < a.n; k++) {
            if (a.mat[i][k] == 0) continue;
            for (int j = 0; j < a.n; j++) {
                res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return res;
}

Matrix power(Matrix a, long long k) {
    Matrix res(a.n);
    for (int i = 0; i < a.n; i++) res.mat[i][i] = 1;
    while (k > 0) {
        if (k & 1) res = multiply(res, a);
        a = multiply(a, a);
        k >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    Matrix a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            a.mat[i][j] = stringToInt128(s);
        }
    }

    long long k;
    cin >> k;
    string p;
    cin >> p;

    Matrix res = power(a, k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << int128ToString(res.mat[i][j]) << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int128 s_sum = 0;
    int128 d_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s_sum += res.mat[i][j];
        }
        d_sum += res.mat[i][i];
    }

    int r = (int)(s_sum % 14);
    if (r < 0) r += 14;

    bool d_is_odd = (d_sum % 2 != 0);
    if (d_is_odd) {
        cout << "Ru" << r << "e30?";
    } else {
        cout << "Ru" << r << "?";
    }

    double t = (double)r + (d_is_odd ? 0.5 : 0.0);

    if (t < 10.5) {
        cout << " Eita, cedo demais.." << endl;
    } else if (t < 12.0) {
        cout << " Ainda bem, vai dar tempo de cochilar antes da aula de " << p << "." << endl;
    } else {
        cout << " Aff.. Nem vai dar tempo de cochilar antes da aula de " << p << "." << endl;
    }

    return 0;
}