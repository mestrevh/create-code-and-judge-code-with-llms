/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    int candies[3] = {X, Y, Z};
    std::sort(candies, candies + 3);

    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (N >= candies[i]) {
            N -= candies[i];
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
