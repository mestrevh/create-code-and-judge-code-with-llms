/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <functional>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

Node* createLinkedList(const vector<int>& elements) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : elements) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int recursiveFunction(Node* head, const char op) {
    if (!head->next) return head->value;
    int nextValue = recursiveFunction(head->next, op);
    return (op == '+') ? head->value + nextValue : head->value - nextValue;
}

int main() {
    int N;
    cin >> N;
    vector<int> elements(N);
    for (int i = 0; i < N; ++i) {
        cin >> elements[i];
    }
    string opStr;
    cin.ignore();
    getline(cin, opStr);
    
    char op = opStr[2]; // 'x op y'
    
    Node* head = createLinkedList(elements);
    int result = recursiveFunction(head, op);
    
    cout << result << endl;

    return 0;
}
