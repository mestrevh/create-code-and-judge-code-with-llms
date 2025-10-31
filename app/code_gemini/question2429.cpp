/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1, n2;
    std::cin >> n1 >> n2;

    std::vector<int> l1(n1);
    for (int i = 0; i < n1; ++i) {
        std::cin >> l1[i];
    }

    std::vector<int> l2(n2);
    for (int i = 0; i < n2; ++i) {
        std::cin >> l2[i];
    }

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) {
        if (l1[i] < l2[j]) {
            std::cout << l1[i] << "\n";
            i++;
        } else {
            std::cout << l2[j] << "\n";
            j++;
        }
    }

    while (i < n1) {
        std::cout << l1[i] << "\n";
        i++;
    }

    while (j < n2) {
        std::cout << l2[j] << "\n";
        j++;
    }

    return 0;
}
