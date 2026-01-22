/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <queue>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    if (n <= 0) {
        return 0;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::queue<std::string> messages;
    std::string message;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, message);
        messages.push(message);
    }

    while (!messages.empty()) {
        std::cout << messages.front() << '\n';
        messages.pop();
    }

    return 0;
}
