/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int X, Y, count = 0;
    std::cin >> X >> Y;
    std::vector<int> sequence(X);
    
    for (int i = 0; i < X; ++i) {
        std::cin >> sequence[i];
        if (sequence[i] == Y) count++;
    }
    
    std::cout << count << std::endl;
    return 0;
}
