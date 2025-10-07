/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int countOccurrences(const std::vector<int>& v, int x) {
    int count = 0;
    for (int element : v) {
        if (element == x) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x;
    std::cin >> x;

    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int result = countOccurrences(v, x);
    std::cout << result << std::endl;

    return 0;
}
