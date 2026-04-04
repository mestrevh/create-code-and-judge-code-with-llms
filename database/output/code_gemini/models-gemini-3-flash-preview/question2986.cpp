/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Node {
    string name;
    long long year;
    Node* next;
    Node(string n, long long y) : name(n), year(y), next(nullptr) {}
};

Node* iterativeMerge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    
    Node dummy("", 0);
    Node* tail = &dummy;
    
    while (a && b) {
        if (a->year < b->year || (a->year == b->year && a->name < b->name)) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    
    if (a) tail->next = a;
    else tail->next = b;
    
    return dummy.next;
}

void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *front = source;
    *back = slow->next;
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
    
    *headRef = iterativeMerge(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    Node* head = nullptr;

    while (getline(cin, name)) {
        if (name.empty()) {
            if (cin.eof()) break;
            continue;
        }
        
        long long year;
        if (!(cin >> year)) break;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        Node* newNode = new Node(name, year);
        newNode->next = head;
        head = newNode;
    }

    if (head) {
        mergeSort(&head);
        
        Node* curr = head;
        while (curr) {
            cout << curr->year << " - " << curr->name << "\n";
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    return 0;
}