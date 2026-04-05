/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    int age;
    Node* next;
    Node(const string& n, int a) : name(n), age(a), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    if (!(cin >> Q)) return 0;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < Q; i++) {
        string N;
        int I;
        cin >> N >> I;
        Node* cur = new Node(N, I);
        if (!head) {
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    int S;
    cin >> S;

    bool first = true;
    Node* cur = head;
    while (cur) {
        if (cur->age == S) {
            if (!first) cout << ' ';
            cout << cur->name;
            first = false;
        }
        cur = cur->next;
    }

    if (first) cout << "Eleven nao tem amigos com essa idade.";

    cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }

    return 0;
}