/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Element {
    string methodName;
    Element* next;

    Element(const string& name, Element* nxt) : methodName(name), next(nxt) {}
};

class CustomStack {
private:
    Element* head;

public:
    CustomStack() : head(nullptr) {}

    ~CustomStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const string& name) {
        head = new Element(name, head);
    }

    string pop() {
        if (isEmpty()) return "";
        Element* temp = head;
        string name = temp->methodName;
        head = head->next;
        delete temp;
        return name;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    for (int i = 1; i <= N; ++i) {
        cout << "Conjunto #" << i << "\n";
        
        CustomStack stack;
        string input;
        
        while (cin >> input) {
            if (input == "return") {
                if (!stack.isEmpty()) {
                    cout << stack.pop() << "\n";
                    if (stack.isEmpty()) {
                        break;
                    }
                }
            } else {
                stack.push(input);
            }
        }
        cout << "\n";
    }

    return 0;
}