/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::deque<std::string> message_queue;
    std::string message;

    // Consume the newline character after reading n
    std::cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, message);
        message_queue.push_back(message);
    }

    while (!message_queue.empty()) {
        std::cout << message_queue.front() << '\n';
        message_queue.pop_front();
    }

    return 0;
}
