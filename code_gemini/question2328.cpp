/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double encontrarMaior(double v, double w, double x, double y, double z) {
    double maior = v;
    if (w > maior) {
        maior = w;
    }
    if (x > maior) {
        maior = x;
    }
    if (y > maior) {
        maior = y;
    }
    if (z > maior) {
        maior = z;
    }
    return maior;
}

int main() {
    double v, w, x, y, z;
    std::cin >> v >> w >> x >> y >> z;
    
    double resultado = encontrarMaior(v, w, x, y, z);
    
    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    
    return 0;
}
