/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c;
    if (std::cin >> a >> b >> c) {
        int cakes_a = a / 2;
        int cakes_b = b / 3;
        int cakes_c = c / 5;
        
        int result = cakes_a;
        if (cakes_b < result) result = cakes_b;
        if (cakes_c < result) result = cakes_c;
        
        std::cout << result << "\n";
    }

    return 0;
}