/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int arr[50];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        std::cout << arr[i] * 2 << "\n";
    }
    return 0;
}
