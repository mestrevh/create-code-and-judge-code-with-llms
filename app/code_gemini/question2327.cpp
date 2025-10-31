/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double menor(double x, double y, double z) {
    double min_val = x;
    if (y < min_val) {
        min_val = y;
    }
    if (z < min_val) {
        min_val = z;
    }
    return min_val;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double x, y, z;
    std::cin >> x >> y >> z;
    
    double resultado = menor(x, y, z);
    
    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    
    return 0;
}
