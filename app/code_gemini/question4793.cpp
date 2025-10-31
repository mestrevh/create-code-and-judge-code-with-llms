/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    double math1_result = (a * b) + (c / d);
    double math2_result = ((a * b) + c) / d;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << math1_result << std::endl;
    std::cout << math2_result << std::endl;
    
    return 0;
}
