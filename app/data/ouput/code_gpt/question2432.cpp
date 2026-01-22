/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>

class Node {
public:
    char method[31];
    Node* next;
    Node(const char* m) {
        strcpy(method, m);
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(const char* method) {
        Node* newNode = new Node(method);
        newNode->next = top;
        top = newNode;
    }

    const char* pop() {
        if (top == nullptr) return nullptr;
        Node* temp = top;
        top = top->next;
        const char* methodName = temp->method;
        delete temp;
        return methodName;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 1; i <= n; ++i) {
        Stack stack;
        std::string input;
        std::string method;
        std::cout << "Conjunto #" << i << std::endl;

        while (std::getline(std::cin, input) && !input.empty()) {
            size_t pos = 0;
            while ((pos = input.find_first_not_of(" \n\t", pos)) != std::string::npos) {
                size_t end = input.find_first_of(" \n\t", pos);
                method = input.substr(pos, end - pos);
                if (method == "return") {
                    if (!stack.isEmpty()) {
                        std::cout << stack.pop() << std::endl;
                    }
                } else {
                    stack.push(method.c_str());
                }
                pos = end;
            }
        }

        std::cout << std::endl;
        stack.clear();
    }

    return 0;
}
