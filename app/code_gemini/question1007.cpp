/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    double sum = 0.0;
    
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            sum += 1.0 / (2 * i + 1);
        } else {
            sum -= 1.0 / (2 * i + 1);
        }
    }
    
    double pi = sum * 4.0;
    
    std::cout << std::fixed << std::setprecision(5) << pi << std::endl;
    
    return 0;
}
