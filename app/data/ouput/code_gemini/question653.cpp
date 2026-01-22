/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, d;
    while (std::cin >> n >> d && (n != 0 || d != 0)) {
        std::string number;
        std::cin >> number;

        std::string result;
        int removals_left = d;

        for (char digit : number) {
            while (!result.empty() && removals_left > 0 && result.back() < digit) {
                result.pop_back();
                removals_left--;
            }
            result.push_back(digit);
        }

        int final_size = n - d;
        result.resize(final_size);

        std::cout << result << '\n';
    }

    return 0;
}
