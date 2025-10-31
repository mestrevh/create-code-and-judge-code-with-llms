/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> heights[i];
    }

    int max_height = 0;
    for (int h = 1; h <= N; ++h) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (heights[i] >= h) {
                count++;
            }
        }
        if (count >= h) {
            max_height = h;
        } else {
            break;
        }
    }

    std::cout << max_height << std::endl;
    return 0;
}
