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

    std::vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    double s;
    std::cin >> s;

    std::sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;
    bool found = false;

    while (left < right) {
        double current_sum = a[left] + a[right];
        if (current_sum == s) {
            found = true;
            break;
        } else if (current_sum < s) {
            left++;
        } else {
            right--;
        }
    }

    if (found) {
        std::cout << "SIM\n";
    } else {
        std::cout << "NAO\n";
    }

    return 0;
}
