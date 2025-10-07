/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int rotations;
    std::cin >> rotations;

    if (n > 0) {
        rotations %= n;
    }
    
    for (int i = rotations; i < n; ++i) {
        std::cout << arr[i] << "\n";
    }
    for (int i = 0; i < rotations; ++i) {
        std::cout << arr[i] << "\n";
    }

    return 0;
}
