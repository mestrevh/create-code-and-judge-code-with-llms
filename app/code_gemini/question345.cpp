/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    while (n--) {
        int a_int, b_int;
        char op;
        std::cin >> a_int >> op >> b_int;

        double a = static_cast<double>(a_int);
        double b = static_cast<double>(b_int);
        double result = 0.0;

        switch (op) {
            case '#':
                result = pow(a, b) * pow(b, a);
                break;
            case '@':
                result = pow(a, b) / pow(b, a);
                break;
            case '&':
                result = (b * sqrt(a)) + (a * sqrt(b));
                break;
            case '%':
                result = (b * sqrt(a)) - (a * sqrt(b));
                break;
        }

        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    }

    return 0;
}
