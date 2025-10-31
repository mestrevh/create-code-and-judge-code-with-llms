/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += (arr[i] % 2 == 0) ? 1 : -1;
    }

    std::cout << sum << std::endl;
    return 0;
}
