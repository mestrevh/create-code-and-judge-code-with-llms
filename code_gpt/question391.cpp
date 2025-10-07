/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, max_iter;
    double tol1, tol2;
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    vector<double> y(n);
    for (int i = 0; i < n; ++i)
        cin >> y[i];

    cin >> max_iter >> tol1 >> tol2;

    double lb_prev = 0.0;
    bool converged = false;

    for (int k = 1; k <= max_iter; ++k) {
        // Multiplicação de matriz por vetor
        vector<double> z(n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                z[i] += A[i][j] * y[j];

        double norm_z = 0.0;
        for (double val : z) norm_z += val * val;
        norm_z = sqrt(norm_z);

        if (fabs(norm_z) < tol2) {
            cout << "O algotimo nao convergiu.\nDivisao por zero na iteracao " << k << ".\n";
            return 0;
        }

        // Normalização
        for (int i = 0; i < n; ++i)
            y[i] = z[i] / norm_z;

        // Estimativa do autovalor utilizando o quociente de Rayleigh
        double lb = 0.0;
        for (int i = 0; i < n; ++i)
            lb += y[i] * z[i];
        
        if (fabs(lb) < tol2) {
            cout << "O algotimo nao convergiu.\nDivisao por zero na iteracao " << k << ".\n";
            return 0;
        }
        
        // Verificação de convergência
        if (k > 1) {
            double error = fabs((lb - lb_prev) / lb);
            if (error < tol1) {
                converged = true;
                cout << "Algoritmo converge com " << k << " iteracoes.\n";
                break;
            }
        }

        lb_prev = lb;

        cout << fixed << setprecision(4);
        cout << "v1_" << k << "\n";
        for (double val : y)
            cout << val << "\n";

        cout << "lb1_" << k << "\n" << lb << "\n\n";
    }

    if (!converged) {
        cout << "Atingiu o numero maximo de iteracoes.\n";
    }
    
    return 0;
}
