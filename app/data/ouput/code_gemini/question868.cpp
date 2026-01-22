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

    int n, d;
    std::cin >> n >> d;

    std::vector<int> matches;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        if (num % 10 == d) {
            matches.push_back(num);
        }
    }

    std::sort(matches.begin(), matches.end());

    std::vector<int> result(5, -1);
    
    int num_to_copy = std::min(5, (int)matches.size());

    if (num_to_copy > 0) {
        std::copy(matches.end() - num_to_copy, matches.end(), result.end() - num_to_copy);
    }
    
    for (int val : result) {
        std::cout << val << '\n';
    }

    return 0;
}
