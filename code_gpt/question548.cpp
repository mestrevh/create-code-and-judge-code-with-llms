/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

struct Node {
    std::vector<int> data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(const std::vector<int>& nums) {
        Node* newNode = new Node;
        newNode->data = nums;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "EMPTY STACK" << std::endl;
            return;
        }
        for (int num : top->data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    std::string command;
    
    while (std::getline(std::cin, command)) {
        if (command == "PUSH") {
            std::string line;
            std::getline(std::cin, line);
            std::istringstream iss(line);
            std::vector<int> nums;
            int num;
            while (iss >> num) {
                nums.push_back(num);
            }
            stack.push(nums);
        } else if (command == "POP") {
            stack.pop();
        }
    }
    return 0;
}
