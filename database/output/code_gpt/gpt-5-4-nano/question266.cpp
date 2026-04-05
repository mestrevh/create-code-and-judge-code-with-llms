/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a;
    int x;
    while (cin >> x) a.push_back(x);

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int v : a) {
        Node* n = new Node(v);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    if (head) {
        Node* sorted = nullptr;
        while (head) {
            Node* cur = head;
            head = head->next;
            if (!sorted || cur->val < sorted->val) {
                cur->next = sorted;
                sorted = cur;
            } else {
                Node* p = sorted;
                while (p->next && p->next->val <= cur->val) p = p->next;
                cur->next = p->next;
                p->next = cur;
            }
        }
        head = sorted;
    }

    bool first = true;
    for (Node* p = head; p; p = p->next) {
        if (!first) cout << ' ';
        first = false;
        cout << p->val;
    }
    cout << "\n";

    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
    return 0;
}