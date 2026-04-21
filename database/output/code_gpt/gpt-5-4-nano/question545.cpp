/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Treap {
    struct Node {
        int key;
        int pr;
        int cnt;
        int sz;
        Node* l;
        Node* r;
        Node(int k, uint32_t pr_) : key(k), pr((int)pr_), cnt(1), sz(1), l(nullptr), r(nullptr) {}
    };

    static uint32_t rng_state;
    static uint32_t rngu() {
        rng_state = rng_state * 1103515245u + 12345u;
        return rng_state;
    }

    Node* root = nullptr;

    static int getsz(Node* t) { return t ? t->sz : 0; }
    static void pull(Node* t) {
        if (!t) return;
        t->sz = t->cnt + getsz(t->l) + getsz(t->r);
    }

    static void rotate_split(Node* t, int key, Node*& a, Node*& b) {
        if (!t) { a = b = nullptr; return; }
        if (key < t->key) {
            rotate_split(t->l, key, a, t->l);
            b = t;
            pull(b);
        } else {
            rotate_split(t->r, key, t->r, b);
            a = t;
            pull(a);
        }
    }

    static Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
        if (a->pr < b->pr) {
            a->r = merge(a->r, b);
            pull(a);
            return a;
        } else {
            b->l = merge(a, b->l);
            pull(b);
            return b;
        }
    }

    static bool findNode(Node* t, int key) {
        while (t) {
            if (key == t->key) return true;
            t = (key < t->key) ? t->l : t->r;
        }
        return false;
    }

    void addKey(int key) {
        if (findNode(root, key)) return;
        root = insertUnique(root, key);
    }

    static Node* insertUnique(Node* t, int key) {
        if (!t) return new Node(key, rngu());
        if (key < t->key) {
            t->l = insertUnique(t->l, key);
            if (t->l->pr < t->pr) t = rotRight(t);
        } else if (key > t->key) {
            t->r = insertUnique(t->r, key);
            if (t->r->pr < t->pr) t = rotLeft(t);
        }
        pull(t);
        return t;
    }

    static Node* rotRight(Node* t) {
        Node* x = t->l;
        t->l = x->r;
        x->r = t;
        pull(t);
        pull(x);
        return x;
    }

    static Node* rotLeft(Node* t) {
        Node* x = t->r;
        t->r = x->l;
        x->l = t;
        pull(t);
        pull(x);
        return x;
    }

    int removeKey(int key) {
        if (!findNode(root, key)) return 0;
        root = eraseKey(root, key);
        return 1;
    }

    static Node* eraseKey(Node* t, int key) {
        if (!t) return nullptr;
        if (key < t->key) {
            t->l = eraseKey(t->l, key);
            pull(t);
            return t;
        } else if (key > t->key) {
            t->r = eraseKey(t->r, key);
            pull(t);
            return t;
        } else {
            Node* res = merge(t->l, t->r);
            delete t;
            return res;
        }
    }

    int countLE(int key) const {
        Node* t = root;
        int ans = 0;
        while (t) {
            if (key < t->key) {
                t = t->l;
            } else {
                ans += getsz(t->l) + t->cnt;
                t = t->r;
            }
        }
        return ans;
    }

    int countRange(int a, int b) const {
        if (a > b) return 0;
        return countLE(b) - countLE(a - 1);
    }

    int secondLargest() const {
        Node* t = root;
        if (!t || (int)root->sz < 2) return -1;
        Node* cur = t;
        while (true) {
            if (cur->r) {
                cur = cur->r;
            } else {
                break;
            }
        }
        int largest = cur->key;
        int second;
        if (cur->l) {
            Node* p = cur->l;
            while (p->r) p = p->r;
            second = p->key;
        } else {
            Node* q = t;
            second = INT_MIN;
            while (q) {
                if (largest <= q->key) {
                    q = q->l;
                } else {
                    second = q->key;
                    q = q->r;
                }
            }
            if (second == INT_MIN) return -1;
        }
        return second;
    }
};

uint32_t Treap::rng_state = 712367821u;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int seedY, z, w, modY, seedX, modX;
    if (!(cin >> N >> seedY >> z >> w >> modY >> seedX >> modX)) return 0;

    vector<int> X(N);
    vector<int> Y(N);
    long long y = seedY;
    for (int i = 0; i < N; i++) {
        Y[i] = (int)y;
        if (i + 1 < N) y = (y * z + w) % modY;
    }

    long long x = seedX;
    for (int i = 0; i < N; i++) {
        X[i] = (int)x;
        if (i + 1 < N) x = x + 1 + (Y[i] % modX);
    }

    Treap bst;

    function<void(int,int)> bst_init = [&](int a, int b) {
        if (a > b) return;
        int c = (int)floor(( (double)(a + b) ) / 2.0);
        bst.addKey(X[c]);
        if (a <= c - 1) bst_init(a, c - 1);
        if (c + 1 <= b) bst_init(c + 1, b);
    };

    bst_init(0, N - 1);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "ADD") {
            long long k; cin >> k;
            int key = (int)k;
            if (!Treap::findNode(bst.root, key)) {
                bst.addKey(key);
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (cmd == "DEL") {
            long long k; cin >> k;
            int key = (int)k;
            cout << bst.removeKey(key) << "\n";
        } else if (cmd == "INT") {
            long long a,b; cin >> a >> b;
            cout << bst.countRange((int)a, (int)b) << "\n";
        } else if (cmd == "SGE") {
            cout << bst.secondLargest() << "\n";
        }
    }
    return 0;
}