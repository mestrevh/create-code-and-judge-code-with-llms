/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <numeric>

using matrix = std::vector<std::vector<double>>;
using vector = std::vector<double>;

vector read_vector_from_line() {
    vector row;
    std::string line;
    std::getline(std::cin, line);
    while (line.length() == 0 && std::cin.good()) {
        std::getline(std::cin, line);
    }
    std::stringstream ss(line);
    double value;
    while (ss >> value) {
        row.push_back(value);
    }
    return row;
}

vector multiply_matrix_vector(const matrix& A, const vector& y) {
    int n = A.size();
    vector z(n, 0.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            z[i] += A[i][j] * y[j];
        }
    }
    return z;
}

double vector_norm(const vector& v) {
    double sum_sq = 0.0;
    for (double val : v) {
        sum_sq += val * val;
    }
    return std::sqrt(sum_sq);
}

double dot_product(const vector& v1, const vector& v2) {
    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

void print_vector(const vector& v, int k) {
    std::cout << "v1_" << k << "\n";
    for (double val : v) {
        std::cout << val << "\n";
    }
}

void print_lambda(double lambda, int k) {
    std::cout << "lb1_" << k << "\n";
    std::cout << lambda << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(4);

    vector first_row = read_vector_from_line();
    int n = first_row.size();
    matrix A(n, vector(n));
    A[0] = first_row;
    for (int i = 1; i < n; ++i) {
        A[i] = read_vector_from_line();
    }

    vector y = read_vector_from_line();

    int max_iter;
    double tol_01, tol_02;
    std::cin >> max_iter >> tol_01 >> tol_02;

    double norm_y = vector_norm(y);
    if (std::abs(norm_y) < tol_02) {
        std::cout << "O algotimo nao convergiu.\n";
        std::cout << "Divisao por zero na iteracao 1.\n";
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        y[i] /= norm_y;
    }

    double lambda_k = 0.0;
    double lambda_prev = 0.0;
    
    int k_final = 0;
    int status = 0; // 0: max_iter, 1: converged, 2: div_by_zero

    for (int k = 1; k <= max_iter; ++k) {
        k_final = k;

        vector z = multiply_matrix_vector(A, y);

        double norm_z = vector_norm(z);
        if (std::abs(norm_z) < tol_02) {
            status = 2;
            break;
        }
        for(size_t i = 0; i < y.size(); ++i) {
            y[i] = z[i] / norm_z;
        }
        
        vector Ay = multiply_matrix_vector(A, y);
        lambda_k = dot_product(y, Ay);

        if (k > 1) {
            std::cout << "\n";
        }
        print_vector(y, k);
        print_lambda(lambda_k, k);
        
        if (k > 1) {
            if (std::abs(lambda_k) < tol_02) {
                status = 2;
                break;
            }
            double error = std::abs((lambda_k - lambda_prev) / lambda_k);
            if (error < tol_01) {
                status = 1;
                break;
            }
        }
        lambda_prev = lambda_k;
    }

    std::cout << "\n";
    if (status == 1) {
        std::cout << "Algoritmo converge com " << k_final << " iteracoes.\n";
    } else if (status == 2) {
        std::cout << "O algotimo nao convergiu.\n";
        std::cout << "Divisao por zero na iteracao " << k_final << ".\n";
    } else {
        std::cout << "Atingiu o numero maximo de iteracoes.\n";
    }

    return 0;
}
