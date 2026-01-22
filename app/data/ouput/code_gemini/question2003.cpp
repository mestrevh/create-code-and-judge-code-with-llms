/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<bool> is_fib(1001, false);
    int a = 0;
    int b = 1;
    while (b <= 1000) {
        is_fib[b] = true;
        int temp = a + b;
        a = b;
        b = temp;
    }

    int n;
    std::cin >> n;

    std::string result = "";
    for (int i = 1; i <= n; ++i) {
        if (is_fib[i]) {
            result += 'O';
        } else {
            result += 'o';
        }
    }

    std::cout << result << std::endl;

    return 0;
}
