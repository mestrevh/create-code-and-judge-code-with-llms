/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

const int MAX_VAL = 10000000;
int counts[MAX_VAL + 1] = {0};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num;
    while (std::cin >> num) {
        if (num >= 0 && num <= MAX_VAL) {
            counts[num]++;
        }
    }

    for (int i = 0; i <= MAX_VAL; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            std::cout << i << "\n";
        }
    }

    return 0;
}
