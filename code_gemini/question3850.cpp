/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double total_sum = 0.0;
    int divisible_by_3_sum = 0;
    
    for (int i = 0; i < 10; ++i) {
        int num;
        std::cin >> num;
        total_sum += num;
        if (num % 3 == 0) {
            divisible_by_3_sum += num;
        }
    }
    
    double average = total_sum / 10.0;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Média: " << average << std::endl;
    std::cout << "Divisíveis: " << divisible_by_3_sum << std::endl;
    
    return 0;
}
