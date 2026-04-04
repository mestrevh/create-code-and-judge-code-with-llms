/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line) && line.empty());
    if (line.empty()) return 0;
    
    stringstream ss(line);
    double val;
    vector<double> row1;
    while (ss >> val) row1.push_back(val);
    
    int N = row1.size();
    if (N == 0) return 0;
    
    vector<vector<double>> A(N, vector<double>(N));
    A[0] = row1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(cin >> A[i][j])) break;
        }
    }

    vector<double> y(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> y[i])) break;
    }

    int K;
    if (!(cin >> K)) K = 0;
    double tol1, tol2;
    if (!(cin >> tol1 >> tol2)) { tol1 = 0; tol2 = 0; }

    double num0 = 0, den0 = 0;
    for (int i = 0; i < N; ++i) {
        double Ay0_i = 0;
        for (int j = 0; j < N; ++j) {
            Ay0_i += A[i][j] * y[j];
        }
        num0 += y[i] * Ay0_i;
        den0 += y[i] * y[i];
    }

    double lb_prev = 0;
    if (abs(den0) >= tol2) {
        lb_prev = num0 / den0;
    }

    bool converged = false;
    int k_conv = 0;
    for (int k = 1; k <= K; ++k) {
        vector<double> z(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                z[i] += A[i][j] * y[j];
            }
        }

        double norm_sq = 0;
        for (int i = 0; i < N; ++i) norm_sq += z[i] * z[i];
        double norm = sqrt(norm_sq);

        if (abs(norm) < tol2) {
            if (k > 1) cout << "\n";
            cout << "O algoritmo nao convergiu. Divisao por zero na iteracao " << k << "." << endl;
            return 0;
        }

        for (int i = 0; i < N; ++i) y[i] = z[i] / norm;

        double lb_curr = 0;
        for (int i = 0; i < N; ++i) {
            double Ay_curr_i = 0;
            for (int j = 0; j < N; ++j) {
                Ay_curr_i += A[i][j] * y[j];
            }
            lb_curr += y[i] * Ay_curr_i;
        }

        if (k > 1) cout << "\n";
        cout << "v1_" << k << "\n";
        for (int i = 0; i < N; ++i) {
            cout << fixed << setprecision(4) << y[i] << "\n";
        }
        cout << "lb1_" << k << "\n";
        cout << fixed << setprecision(4) << lb_curr << "\n";

        if (abs(lb_curr) < tol2) {
            cout << "\nO algoritmo nao convergiu. Divisao por zero na iteracao " << k << "." << endl;
            return 0;
        }

        double err = abs((lb_curr - lb_prev) / lb_curr);
        if (err < tol1) {
            converged = true;
            k_conv = k;
            break;
        }
        lb_prev = lb_curr;
    }

    cout << "\n";
    if (converged) {
        cout << "Algoritmo converge com " << k_conv << " iteracoes." << endl;
    } else {
        cout << "Atingiu o numero maximo de iteracoes." << endl;
    }

    return 0;
}