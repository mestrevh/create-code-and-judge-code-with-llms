/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long n;
    if (std::cin >> n) {
        std::cout << "Essas malandra, assanhadinha, que so quer ";
        for (long long i = 0; i < n; ++i) {
            std::cout << "vrau";
            if (i < n - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    
    return 0;
}