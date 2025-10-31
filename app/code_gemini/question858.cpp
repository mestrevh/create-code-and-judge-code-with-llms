/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double a, b;
    
    // As the sample output shows prompts, this solution will replicate that behavior.
    // In a typical competitive programming environment, prompts are not printed.
    // However, to match the provided example, they are included here.
    
    // A solution for multiple test cases without prompts would look like this:
    /*
    while (std::cin >> a >> b) {
        std::cout << "Soma: " << std::fixed << std::setprecision(1) << a + b << std::endl;
    }
    */
    
    // Adhering to the single provided sample case:
    std::cout << "Digite um numero:" << std::endl;
    std::cin >> a;
    std::cout << "Digite outro numero:" << std::endl;
    std::cin >> b;
    
    std::cout << "Soma: " << std::fixed << std::setprecision(1) << a + b << std::endl;
    
    return 0;
}
