/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    for (int i = 1; i < N - 1; ++i) {
        if (nums[i - 1] == nums[i] - 1 && nums[i + 1] == nums[i] + 1) {
            std::cout << nums[i] << std::endl;
        }
    }

    return 0;
}
