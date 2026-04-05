/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<long double>> A;
    string line;
    vector<long double> firstRow;
    bool gotAny = false;

    auto parseNums = [&](const string& s) {
        vector<long double> v;
        size_t i = 0, n = s.size();
        while (i < n) {
            while (i < n && isspace((unsigned char)s[i])) i++;
            if (i >= n) break;
            bool neg = false;
            if (s[i] == '+' || s[i] == '-') {
                neg = (s[i] == '-');
                i++;
            }
            long double mant = 0;
            bool hasInt = false;
            while (i < n && isdigit((unsigned char)s[i])) {
                hasInt = true;
                mant = mant * 10 + (s[i] - '0');
                i++;
            }
            long double frac = 0;
            long double div = 1;
            if (i < n && s[i] == '.') {
                i++;
                while (i < n && isdigit((unsigned char)s[i])) {
                    frac = frac * 10 + (s[i] - '0');
                    div *= 10;
                    i++;
                }
            }
            long double val = mant + frac / div;

            if (i < n && (s[i] == 'e' || s[i] == 'E')) {
                i++;
                bool expNeg = false;
                if (i < n && (s[i] == '+' || s[i] == '-')) {
                    expNeg = (s[i] == '-');
                    i++;
                }
                long long exp = 0;
                while (i < n && isdigit((unsigned char)s[i])) {
                    exp = exp * 10 + (s[i] - '0');
                    i++;
                }
                long double p = pow((long double)10.0, (long double)exp);
                val = expNeg ? val / p : val * p;
            }

            if (neg) val = -val;
            v.push_back(val);

            while (i < n && !isspace((unsigned char)s[i])) i++;
        }
        return v;
    };

    while (getline(cin, line)) {
        bool nonspace = false;
        for (char c : line) if (!isspace((unsigned char)c)) { nonspace = true; break; }
        if (!nonspace) continue;
        vector<long double> row = parseNums(line);
        if (row.empty()) continue;
        gotAny = true;
        if (firstRow.empty()) firstRow = row;
        A.push_back(row);
    }

    if (!gotAny) return 0;
    int n = (int)A.size();
    if (n == 0) return 0;

    int m = (int)A[0].size();
    if (m != n) {
        for (int i = 0; i < n; i++) A[i].resize(n, 0);
    }

    vector<vector<long double>> B(n, vector<long double>(n, 0));
    for (int i = 0; i < n; i++) B[i][i] = 1;

    vector<long double> p(n + 1, 0);
    vector<long double> s(n + 1, 0);

    auto matMul = [&](const vector<vector<long double>>& X, const vector<vector<long double>>& Y) {
        vector<vector<long double>> R(n, vector<long double>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                long double xik = X[i][k];
                if (xik == 0) continue;
                for (int j = 0; j < n; j++) R[i][j] += xik * Y[k][j];
            }
        }
        return R;
    };

    auto trace = [&](const vector<vector<long double>>& X) {
        long double t = 0;
        for (int i = 0; i < n; i++) t += X[i][i];
        return t;
    };

    for (int k = 1; k <= n; k++) {
        vector<vector<long double>> AB = matMul(A, B);
        s[k] = trace(AB);
        p[k] = -s[k] / (long double)k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                B[i][j] = AB[i][j] + (i == j ? p[k] : 0);
            }
        }
    }

    auto fixZero = [&](long double x) {
        if (fabsl(x) < 1e-10L) return (long double)0;
        return x;
    };

    cout.setf(std::ios::fmtflags(0), std::ios::floatfield);
    cout << setprecision(2);

    for (int k = 1; k < n; k++) {
        long double val = fixZero(s[k]);
        cout << scientific << (double)val << "e+00";
    }

    return 0;
}