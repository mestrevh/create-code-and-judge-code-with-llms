/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

char rot13(char c) {
    if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + 13) % 26;
    }
    if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + 13) % 26;
    }
    return c;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string custom_alphabet;
    std::cin >> custom_alphabet;

    int dominance_map[256] = {0};
    for (int i = 0; i < custom_alphabet.length(); ++i) {
        dominance_map[static_cast<unsigned char>(custom_alphabet[i])] = i;
    }

    int N;
    std::cin >> N;

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i = 0; i < N; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "PUSH") {
            std::string msg;
            std::cin >> msg;
            for (char c : msg) {
                pq.push(dominance_map[static_cast<unsigned char>(c)]);
            }
        } else { // command == "POP"
            int M;
            std::cin >> M;
            for (int j = 0; j < M; ++j) {
                int top_dominance = pq.top();
                pq.pop();
                char original_char = custom_alphabet[top_dominance];
                std::cout << rot13(original_char);
            }
            std::cout << "\n";
        }
    }

    return 0;
}
