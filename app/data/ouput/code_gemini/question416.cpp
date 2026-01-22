/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    while (n--) {
        int x, b;
        std::cin >> x >> b;

        if (x == 0) {
            std::cout << "0\n";
            continue;
        }

        std::stack<char> result_stack;
        const char digits[] = "0123456789ABCDEF";

        while (x > 0) {
            result_stack.push(digits[x % b]);
            x /= b;
        }

        while (!result_stack.empty()) {
            std::cout << result_stack.top();
            result_stack.pop();
        }
        std::cout << '\n';
    }
    return 0;
}
