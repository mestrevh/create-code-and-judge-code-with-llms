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
    if (n < 3) {
        return 0;
    }
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i - 1] == arr[i] - 1 && arr[i + 1] == arr[i] + 1) {
            std::cout << arr[i] << "\n";
        }
    }
    return 0;
}
