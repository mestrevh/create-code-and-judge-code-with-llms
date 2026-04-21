/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    unsigned char ch;
    int freq;
    Node* next;
    Node(unsigned char c, int f) : ch(c), freq(f), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) return 0;
    vector<int> cnt(256, 0);
    for (unsigned char c : s) cnt[c]++;

    struct Item { unsigned char c; int f; };
    vector<Item> items;
    items.reserve(256);
    for (int i = 0; i < 256; i++) {
        if (cnt[i]) items.push_back(Item{(unsigned char)i, cnt[i]});
    }

    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        if (a.f != b.f) return a.f > b.f;
        return a.c < b.c;
    });

    Node* head = nullptr;
    Node* tail = nullptr;
    for (auto &it : items) {
        Node* nd = new Node(it.c, it.f);
        if (!head) head = tail = nd;
        else { tail->next = nd; tail = nd; }
    }

    for (Node* cur = head; cur; cur = cur->next) {
        char outChar = (char)cur->ch;
        if (outChar == '\n') outChar = '\n';
        cout << outChar << ' ' << cur->freq;
        if (cur->next) cout << "\n";
    }

    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    return 0;
}