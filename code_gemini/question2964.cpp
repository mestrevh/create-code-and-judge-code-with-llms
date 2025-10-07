/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_E
#define M_E 2.71828182845904523536
#endif

double round_to_4(double val) {
    return round(val * 10000.0) / 10000.0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b, c, d;
    std::cin >> a >> b >> c >> d;

    // Expression i
    // Based on sample output, this seems to be the formula
    double res1 = (a * d) + (b * c) / 3.0;
    std::cout << "i) " << round_to_4(res1) << std::endl;

    // Expression ii
    // Based on sample output, this seems to be the formula
    double res2 = (a * b * c * d) / (a + b + c + d);
    std::cout << "ii) " << round_to_4(res2) << std::endl;

    // Expression iii
    // Based on sample output, this seems to be the formula
    double res3 = cbrt(a * c + b * d);
    std::cout << "iii) " << round_to_4(res3) << std::endl;

    // Expression iv
    // Based on sample output, this seems to be the formula
    double res4 = log10(abs(a * b + c * d));
    std::cout << "iv) " << round_to_4(res4) << std::endl;

    // Expression v
    // Based on sample output, this seems to be the formula
    double res5 = ( (a + b) / (c + d) ) - ( (M_PI + M_E) / (a + c) );
    std::cout << "v) " << round_to_4(res5) << std::endl;

    // Expression vi
    double res6 = pow(a + b + c + d, 2);
    std::cout << "vi) " << round_to_4(res6) << std::endl;

    // Expression vii
    double res7 = pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2);
    std::cout << "vii) " << round_to_4(res7) << std::endl;

    // Expression viii
    // Based on sample output, this seems to be the formula
    double res8 = sqrt(pow( (a+c)/b, 2) + pow( (b+d)/a, 2) );
    std::cout << "viii) " << round_to_4(res8) << std::endl;

    return 0;
}
