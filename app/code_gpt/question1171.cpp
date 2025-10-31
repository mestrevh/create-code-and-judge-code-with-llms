/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> count(10000001, 0);
    int n, num;

    while (std::cin >> num) {
        count[num]++;
        n++;
    }

    for (int i = 0; i < count.size(); ++i) {
        while (count[i]-- > 0) {
            std::cout << i << "\n";
        }
    }

    return 0;
}
