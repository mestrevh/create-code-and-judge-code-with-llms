/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;
    Node* tail = nullptr;

    int x;
    while (cin >> x) {
        if (x == 0) break;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    int M;
    if (!(cin >> M)) M = 0;

    bool found = false;
    for (Node* cur = head; cur; cur = cur->next) {
        if (cur->val == M) {
            found = true;
            break;
        }
    }

    if (found) cout << "Comunicacao estabelecida";
    else cout << "404 not found";

    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }

    return 0;
}