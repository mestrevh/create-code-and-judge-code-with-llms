/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::stack<char> textStack;

    for (char c : input) {
        if (c == '<') {
            std::string tag;
            while (c != '>' && std::cin.get(c)) {
                tag += c;
            }
            tag += '>';
            if (tag == "<B>" || tag == "<b>") {
                if (!textStack.empty()) textStack.pop();
            }
            else if (tag == "<Z>" || tag == "<z>") {
                // Ignored for other functionality
            }
        } else {
            textStack.push(c);
        }
    }

    std::string correctedText;
    while (!textStack.empty()) {
        correctedText.insert(correctedText.begin(), textStack.top());
        textStack.pop();
    }

    std::cout << correctedText << std::endl;
    return 0;
}
