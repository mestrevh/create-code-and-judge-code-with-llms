/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string key;
    int cnt;
    Node* next;
    Node(const string& k, int c) : key(k), cnt(c), next(nullptr) {}
};

class LinkedListMultiset {
    Node* head;
public:
    LinkedListMultiset() : head(nullptr) {}
    ~LinkedListMultiset() { clear(); }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head = nullptr;
    }

    int decrementIfExists(const string& k) {
        Node* cur = head;
        while (cur) {
            if (cur->key == k) {
                if (cur->cnt > 0) {
                    cur->cnt--;
                    return 1;
                }
                return 0;
            }
            cur = cur->next;
        }
        return 0;
    }

    void add(const string& k) {
        Node* cur = head;
        while (cur) {
            if (cur->key == k) {
                cur->cnt++;
                return;
            }
            cur = cur->next;
        }
        Node* n = new Node(k, 1);
        n->next = head;
        head = n;
    }

    vector<string> remainingInOrderInput() {
        vector<string> keys;
        vector<int> counts;
        Node* cur = head;
        while (cur) {
            keys.push_back(cur->key);
            counts.push_back(cur->cnt);
            cur = cur->next;
        }
        vector<pair<string,int>> items;
        for (size_t i = 0; i < keys.size(); i++) items.push_back({keys[i], counts[i]});

        reverse(items.begin(), items.end());

        vector<string> res;
        for (auto &it : items) {
            for (int i = 0; i < it.second; i++) res.push_back(it.first);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedListMultiset aljava;

    string s;
    while (cin >> s) {
        if (s == "Recarga feita") break;
        aljava.add(s);
    }

    vector<string> firedOutputs;
    while (cin >> s) {
        if (s == "Fim da simulacao") break;
        int ok = aljava.decrementIfExists(s);
        if (ok) firedOutputs.push_back("Flecha disparada");
        else firedOutputs.push_back("Flecha nao encontrada");
    }

    for (auto &x : firedOutputs) cout << x << "\n";

    vector<string> rem = aljava.remainingInOrderInput();
    cout << "Flechas que sobraram:";
    for (auto &x : rem) cout << " " << x;
    return 0;
}