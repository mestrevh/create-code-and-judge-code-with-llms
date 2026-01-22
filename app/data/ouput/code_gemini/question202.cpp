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

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n <= 2) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int count = 0;
    int i = 0;
    while (i < n) {
        count++;

        if (i >= n - 1) {
            break;
        }

        long long r = (long long)a[i + 1] - a[i];

        int j = i + 2;
        while (j < n) {
            if ((long long)a[j] - a[j - 1] == r) {
                j++;
            } else {
                break;
            }
        }

        i = j;
    }

    std::cout << count << std::endl;

    return 0;
}
