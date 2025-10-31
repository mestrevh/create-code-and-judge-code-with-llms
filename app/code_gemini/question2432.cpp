/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

class Node {
public:
    std::string data;
    Node* next;

    Node(std::string val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(const std::string& val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    std::string pop() {
        if (isEmpty()) {
            return ""; 
        }
        Node* temp = top;
        std::string popped_data = temp->data;
        top = top->next;
        delete temp;
        return popped_data;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cout << "Conjunto #" << i << "\n";
        Stack callStack;
        std::string command;

        while (std::cin >> command) {
            if (command == "return") {
                std::cout << callStack.pop() << "\n";
                if (callStack.isEmpty()) {
                    break;
                }
            } else {
                callStack.push(command);
            }
        }
        std::cout << "\n";
    }

    return 0;
}
