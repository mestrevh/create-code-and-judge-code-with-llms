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

    vector<int> vals;
    int x;
    while (cin >> x) vals.push_back(x);

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int v : vals) {
        Node* n = new Node(v);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;

    Node* p = head;
    bool first = true;
    while (p) {
        if (!first) cout << ' ';
        first = false;
        cout << p->val;
        p = p->next;
    }
    return 0;
}