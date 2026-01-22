/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <list>
#include <memory>

class SetOfStacks {
private:
    int capacity;
    std::list<std::stack<int>> stacks;

public:
    SetOfStacks(int cap) : capacity(cap) {}

    void push(int value) {
        if (stacks.empty() || stacks.front().size() == capacity) {
            stacks.push_front(std::stack<int>());
        }
        stacks.front().push(value);
    }

    void pop() {
        if (stacks.empty()) {
            return;
        }
        stacks.front().pop();
        if (stacks.front().empty()) {
            stacks.pop_front();
        }
    }

    void print() const {
        std::cout << "Conjunto de pilhas:\n";
        if (stacks.empty()) {
            std::cout << "conjunto de pilhas vazio!\n";
        } else {
            for (const auto& s : stacks) {
                std::cout << "pilha:\n";
                std::stack<int> temp = s;
                while (!temp.empty()) {
                    std::cout << temp.top() << " ";
                    temp.pop();
                }
                std::cout << "\n";
            }
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::unique_ptr<SetOfStacks> set_of_stacks;
    bool first_output = true;

    for (int k = 0; k < n; ++k) {
        char cmd;
        std::cin >> cmd;

        if (cmd == 'c') {
            int capacity;
            std::cin >> capacity;
            set_of_stacks = std::make_unique<SetOfStacks>(capacity);
        } else {
            if (!first_output) {
                std::cout << "\n";
            }
            
            if (cmd == 'i') {
                int value;
                std::cin >> value;
                if (set_of_stacks) {
                    set_of_stacks->push(value);
                }
            } else if (cmd == 'r') {
                if (set_of_stacks) {
                    set_of_stacks->pop();
                }
            }
            
            if (set_of_stacks) {
                set_of_stacks->print();
            }
            
            first_output = false;
        }
    }

    return 0;
}
