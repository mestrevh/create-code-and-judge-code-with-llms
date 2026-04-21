/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* prev;
    Node* next;
    Node(char v = 0) : val(v), prev(nullptr), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;
    if (!s.empty() && s.back() == '\r') s.pop_back();

    Node* head = new Node();
    Node* tail = new Node();
    head->next = tail;
    tail->prev = head;

    Node* cur = head;

    for (char c : s) {
        if (c == '[') {
            cur = head;
        } else if (c == ']') {
            cur = tail->prev;
        } else {
            Node* node = new Node(c);
            Node* after = cur->next;
            cur->next = node;
            node->prev = cur;
            node->next = after;
            after->prev = node;
            cur = node;
        }
    }

    Node* p = head->next;
    while (p != tail) {
        cout << p->val;
        p = p->next;
    }

    Node* x = head;
    while (x) {
        Node* nxt = x->next;
        delete x;
        if (x == tail) break;
        x = nxt;
    }

    return 0;
}