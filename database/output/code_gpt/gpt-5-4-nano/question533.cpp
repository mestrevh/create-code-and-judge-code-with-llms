/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct HashSet {
    struct Node {
        int key;
        Node* next;
        Node(int k, Node* n) : key(k), next(n) {}
    };

    vector<Node*> bucket;
    int m;
    int n;
    int maxListLen;
    int maxLoadDen;

    HashSet() {
        m = 7;
        bucket.assign(m, nullptr);
        n = 0;
        maxListLen = 0;
        maxLoadDen = 4;
    }

    int modHash(int k, int mm) const {
        return k % mm;
    }

    void clearBuckets() {
        for (auto &head : bucket) {
            while (head) {
                Node* t = head;
                head = head->next;
                delete t;
            }
        }
        bucket.clear();
    }

    void recomputeStats() {
        n = 0;
        maxListLen = 0;
        for (int i = 0; i < m; i++) {
            int len = 0;
            Node* cur = bucket[i];
            while (cur) {
                len++;
                n++;
                cur = cur->next;
            }
            maxListLen = max(maxListLen, len);
        }
    }

    void rehash() {
        vector<Node*> old = bucket;
        int oldm = m;

        int newm = 2 * oldm - 1;
        bucket.assign(newm, nullptr);
        m = newm;

        int oldTotal = n;
        (void)oldTotal;

        maxListLen = 0;
        n = 0;

        for (int i = 0; i < oldm; i++) {
            vector<int> keys;
            Node* cur = old[i];
            while (cur) {
                keys.push_back(cur->key);
                Node* t = cur;
                cur = cur->next;
                delete t;
            }
            for (int k : keys) {
                int idx = modHash(k, m);
                Node* head = bucket[idx];
                bucket[idx] = new Node(k, head);
                n++;
                int len = 0;
                for (Node* p = bucket[idx]; p; p = p->next) len++;
                maxListLen = max(maxListLen, len);
            }
        }
    }

    pair<int,int> ensureAddAndCount(int k) {
        int idx = modHash(k, m);
        Node* cur = bucket[idx];
        int c = 1;
        while (cur) {
            if (cur->key == k) return {0, c};
            cur = cur->next;
            c++;
        }
        bucket[idx] = new Node(k, bucket[idx]);
        n++;
        int len = 0;
        for (Node* p = bucket[idx]; p; p = p->next) len++;
        maxListLen = max(maxListLen, len);

        if ((double)n / (double)m >= 0.75) {
            rehash();
        }
        return {1, c};
    }

    pair<int,int> hasAndCount(int k) {
        int idx = modHash(k, m);
        Node* cur = bucket[idx];
        int c = 1;
        while (cur) {
            if (cur->key == k) return {1, c};
            cur = cur->next;
            c++;
        }
        return {0, c};
    }

    pair<int,int> delAndCount(int k) {
        int idx = modHash(k, m);
        Node* cur = bucket[idx];
        if (!cur) return {0, 1};
        int c = 1;
        Node* prev = nullptr;
        while (cur) {
            if (cur->key == k) {
                if (prev) prev->next = cur->next;
                else bucket[idx] = cur->next;
                delete cur;
                n--;
                int newMax = 0;
                for (int i = 0; i < m; i++) {
                    int len = 0;
                    for (Node* p = bucket[i]; p; p = p->next) len++;
                    newMax = max(newMax, len);
                }
                maxListLen = newMax;
                return {1, c};
            }
            prev = cur;
            cur = cur->next;
            c++;
        }
        return {0, c};
    }

    string prtLine(int opIndex) const {
        int mm = m;
        int nn = n;
        int ll = maxListLen;
        return to_string(opIndex) + " " + to_string(mm) + " " + to_string(nn) + " " + to_string(ll);
    }

    ~HashSet() { clearBuckets(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    HashSet hs;
    string op;
    long long idx = 0;

    while (true) {
        if (!(cin >> op)) break;
        if (op == "ADD") {
            int k;
            cin >> k;
            auto [r, c] = hs.ensureAddAndCount(k);
            cout << idx << " " << r << " " << c << "\n";
        } else if (op == "DEL") {
            int k;
            cin >> k;
            auto [r, c] = hs.delAndCount(k);
            cout << idx << " " << r << " " << c << "\n";
        } else if (op == "HAS") {
            int k;
            cin >> k;
            auto [r, c] = hs.hasAndCount(k);
            cout << idx << " " << r << " " << c << "\n";
        } else if (op == "PRT") {
            cout << hs.prtLine((int)idx) << "\n";
        }
        idx++;
    }
    return 0;
}