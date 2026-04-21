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

    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
        if (!(cin >> a[i])) return 0;
    }

    Node* head = nullptr;
    for (int x : a) {
        if (!head || x < head->val) {
            Node* n = new Node(x);
            n->next = head;
            head = n;
        } else {
            Node* cur = head;
            while (cur->next && cur->next->val <= x) cur = cur->next;
            Node* n = new Node(x);
            n->next = cur->next;
            cur->next = n;
        }
    }

    Node* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << ' ';
        first = false;
        cout << cur->val;
        cur = cur->next;
    }
    cout << '\n';

    cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    return 0;
}