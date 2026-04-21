/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* sortedMerge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    
    Node* result = nullptr;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

void split(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;
    
    Node* a;
    Node* b;
    
    split(head, &a, &b);
    
    mergeSort(&a);
    mergeSort(&b);
    
    *headRef = sortedMerge(a, b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int val;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    while (std::cin >> val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    if (head) {
        mergeSort(&head);
        
        Node* curr = head;
        bool first = true;
        while (curr) {
            if (!first) std::cout << " ";
            std::cout << curr->data;
            first = false;
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        std::cout << std::endl;
    }
    
    return 0;
}