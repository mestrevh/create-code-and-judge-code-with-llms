/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string val;
    Node* next;
    Node(const string& v) : val(v), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;
    Node* tail = nullptr;

    string line;
    while (true) {
        if (!getline(cin, line)) break;
        if (line == "The End") break;
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (!line.empty() && !head) {
            head = tail = new Node(line);
        } else {
            if (!head) {
                head = tail = new Node(line);
            } else {
                tail->next = new Node(line);
                tail = tail->next;
            }
        }
    }

    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        if (!head) continue;

        Node* prev = nullptr;
        Node* cur = head;
        while (cur) {
            if (cur->val == line) break;
            prev = cur;
            cur = cur->next;
        }
        if (!cur) continue;
        if (prev) prev->next = cur->next;
        else head = cur->next;
        if (cur == tail) {
            tail = prev;
        }
        delete cur;
    }

    if (!head) {
        cout << "U gotta null pointer ma man";
        return 0;
    }

    Node* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << "\n";
        cout << cur->val;
        first = false;
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    return 0;
}