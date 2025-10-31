/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::string text_buffer;
    std::stack<char> undo_stack;

    for (size_t i = 0; i < line.length(); ) {
        if (i + 2 < line.length() && line[i] == '<' && line[i + 2] == '>') {
            char command = line[i + 1];
            if (command == 'B' || command == 'b') {
                if (!text_buffer.empty()) {
                    undo_stack.push(text_buffer.back());
                    text_buffer.pop_back();
                }
                i += 3;
            } else if (command == 'Z' || command == 'z') {
                if (!undo_stack.empty()) {
                    text_buffer.push_back(undo_stack.top());
                    undo_stack.pop();
                }
                i += 3;
            } else {
                text_buffer.push_back(line[i]);
                i++;
            }
        } else {
            text_buffer.push_back(line[i]);
            i++;
        }
    }

    std::cout << text_buffer << '\n';

    return 0;
}
