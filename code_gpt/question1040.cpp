/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

std::string rot13(const std::string &s) {
    std::string result;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z')
            result += (c - 'A' + 13) % 26 + 'A';
        else if (c >= 'a' && c <= 'z')
            result += (c - 'a' + 13) % 26 + 'a';
        else
            result += c;
    }
    return result;
}

int main() {
    std::string alphabet;
    std::cin >> alphabet;
    std::unordered_map<char, int> order;
    for (int i = 0; i < alphabet.size(); ++i)
        order[alphabet[i]] = i;

    int N;
    std::cin >> N;
    std::priority_queue<std::pair<int, char>> pq;
    std::string message;

    std::string instruction;
    std::cin.ignore();
    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, instruction);
        if (instruction.substr(0, 4) == "PUSH") {
            std::string msg = instruction.substr(5);
            for (char c : msg)
                pq.push({order[c], c});
        } else if (instruction.substr(0, 4) == "POP ") {
            int M = std::stoi(instruction.substr(4));
            std::string output;
            for (int j = 0; j < M; ++j) {
                if (!pq.empty()) {
                    output += pq.top().second;
                    pq.pop();
                }
            }
            std::cout << rot13(output) << '\n';
        }
    }
    return 0;
}
