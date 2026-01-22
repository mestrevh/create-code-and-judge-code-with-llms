/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

void convertToMeters(double& val, double& uncertainty, char unit) {
    if (unit == 'd') {
        val /= 10.0;
        uncertainty /= 10.0;
    } else if (unit == 'c') {
        val /= 100.0;
        uncertainty /= 100.0;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a1, b1, a2, b2;
    char x1, x2;

    std::cin >> a1 >> b1 >> x1;
    std::cin >> a2 >> b2 >> x2;

    convertToMeters(a1, b1, x1);
    convertToMeters(a2, b2, x2);

    double min1 = a1 - b1;
    double max1 = a1 + b1;
    double min2 = a2 - b2;
    double max2 = a2 + b2;

    if (max1 >= min2 && max2 >= min1) {
        std::cout << "forte." << std::endl;
    } else {
        std::cout << "isso tem cara de desencadear um evento de distorcao espacial na proxima questao do meme man..." << std::endl;
    }

    return 0;
}
