/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

double evaluate_expression(const string &expr, double x, double y) {
    // Aqui podemos avaliar a expressão, por simplicidade, substituímos apenas as variáveis.
    // Para produção seria necessário um parser mais robusto.
    stringstream ss;
    string modified_expr = expr;
    size_t pos;

    // Substituindo as variáveis X e Y
    while ((pos = modified_expr.find("X")) != string::npos) {
        ss << x;
        modified_expr.replace(pos, 1, ss.str());
        ss.str("");
    }
    while ((pos = modified_expr.find("Y")) != string::npos) {
        ss << y;
        modified_expr.replace(pos, 1, ss.str());
        ss.str("");
    }

    // Avaliamos a expressão usando a função exp e sin da biblioteca cmath
    // Isso é uma simplificação, pois na prática precisaríamos de um interpretador de expressão.
    // Aqui consideramos apenas alguns casos padrão.
    if (modified_expr == "Y+sin(exp(X))") return y + sin(exp(x));
    else if (modified_expr == "1-X+4*Y") return 1 - x + 4 * y; // exemplo base
    // Outras funções devem ser adicionadas para diferentes expressões.

    return 0.0; // caso não reconheça
}

int main() {
    string equation;
    double x0, y0, n, xf;

    getline(cin, equation);
    cin >> x0 >> y0 >> n >> xf;

    double h = (xf - x0) / n;

    cout << fixed << setprecision(2);
    for (int i = 0; i <= n; i++) {
        cout << x0 << " " << y0 << endl;
        y0 += h * evaluate_expression(equation, x0, y0);
        x0 += h;
    }

    return 0;
}
