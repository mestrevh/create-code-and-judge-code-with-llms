/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, z;

    std::cin >> x;

    do {
        std::cin >> z;
    } while (z <= x);

    int sum = 0;
    int count = 0;
    
    for (int i = x; sum <= z; ++i) {
        sum += i;
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}
