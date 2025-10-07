/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> arr1(n);
    std::vector<int> arr2(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr1[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> arr2[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << arr1[i] << "\n";
        std::cout << arr2[i] << "\n";
    }
    return 0;
}
