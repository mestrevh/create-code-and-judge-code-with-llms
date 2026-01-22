/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void process_student() {
    long long x_ll, y_ll, k;
    std::cin >> x_ll >> y_ll >> k;

    double x = static_cast<double>(x_ll);
    double y = static_cast<double>(y_ll);
    const double E = 2.71;

    double iaf = (x * x * E) / y;

    std::string description;
    if (iaf < 100) {
        description = "Morador do Grad.";
    } else if (iaf < 200) {
        description = "Faz um L.";
    } else if (iaf < 300) {
        description = "Tá safe.";
    } else if (iaf < 400) {
        description = "Conserta Impressoras.";
    } else if (iaf < 500) {
        description = "Top 100.";
    } else {
        description = "Sem volta.";
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "O aluno de índice " << k << " possui o valor IAF igual a " << iaf << " e a descrição de " << description << "." << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    process_student();
    process_student();
    process_student();

    return 0;
}
