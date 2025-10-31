/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string a, b;
    std::cin >> a >> b;
    std::map<std::string, int> angulos;
    angulos["norte"] = 0;
    angulos["leste"] = 90;
    angulos["sul"] = 180;
    angulos["oeste"] = 270;
    int angulo_a = angulos[a];
    int angulo_b = angulos[b];
    int diff = std::abs(angulo_a - angulo_b);
    int resultado = std::min(diff, 360 - diff);
    std::cout << resultado << std::endl;
    return 0;
}
