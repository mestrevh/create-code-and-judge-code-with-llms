/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <numeric>

double trace(const std::vector<std::vector<double>>& m) {
    double sum = 0.0;
    if (m.empty()) {
        return 0.0;
    }
    for (size_t i = 0; i < m.size(); ++i) {
        sum += m[i][i];
    }
    return sum;
}

std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b) {
    size_t n = a.size();
    std::vector<std::vector<double>> result(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::vector<double>> A;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        std::stringstream ss(line);
        std::vector<double> row;
        double val;
        while (ss >> val) {
            row.push_back(val);
        }
        if (!row.empty()) {
            A.push_back(row);
        }
    }

    if (A.empty()) {
        return 0;
    }

    size_t n = A.size();

    std::vector<double> s(n + 1);
    std::vector<std::vector<double>> current_A_power = A;

    for (size_t k = 1; k <= n; ++k) {
        s[k] = trace(current_A_power);
        if (k < n) {
            current_A_power = multiply(current_A_power, A);
        }
    }

    std::vector<double> p(n + 1);
    if (n > 0) {
        p[1] = -s[1];
        for (size_t k = 2; k <= n; ++k) {
            double sum_term = 0.0;
            for (size_t j = 1; j < k; ++j) {
                sum_term += p[j] * s[k - j];
            }
            p[k] = -(s[k] + sum_term) / static_cast<double>(k);
        }
    }

    std::cout << std::scientific << std::setprecision(2);
    std::cout.unsetf(std::ios_base::uppercase);

    for (size_t k = 1; k <= n; ++k) {
        std::cout << s[k] << (k == n ? "" : " ");
    }
    std::cout << std::endl;

    for (size_t k = 1; k <= n; ++k) {
        double val = p[k];
        if (std::abs(val) < 1e-10) {
            val = 0.0;
        }
        std::cout << val << (k == n ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}
