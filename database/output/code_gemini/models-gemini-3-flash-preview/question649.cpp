/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct Node {
    int val, size;
    unsigned int priority;
    Node *l, *r;
} pool[100005];

int pPtr;
mt19937 rng(42);

int getSize(Node* t) {
    return t ? t->size : 0;
}

void update(Node* t) {
    if (t) t->size = 1 + getSize(t->l) + getSize(t->r);
}

void split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    int curSize = getSize(t->l);
    if (curSize < k) {
        split(t->r, k - curSize - 1, t->r, r);
        l = t;
    } else {
        split(t->l, k, l, t->l);
        r = t;
    }
    update(t);
}

Node* merge(Node* l, Node* r) {
    if (!l || !r) return l ? l : r;
    if (l->priority > r->priority) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

Node* create(int v) {
    Node* res = &pool[pPtr++];
    res->val = v;
    res->priority = rng();
    res->size = 1;
    res->l = res->r = nullptr;
    return res;
}

bool firstElement;
void printTreap(Node* t) {
    if (!t) return;
    printTreap(t->l);
    if (!firstElement) cout << " ";
    cout << t->val;
    firstElement = false;
    printTreap(t->r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while (cin >> N >> M && (N || M)) {
        vector<int> X(M + 1);
        for (int i = 1; i <= M; ++i) {
            cin >> X[i];
        }

        pPtr = 0;
        Node* root = nullptr;

        for (int i = M + 1; i <= N; ++i) {
            root = merge(root, create(i));
        }

        for (int i = M; i >= 1; --i) {
            Node *L, *R;
            split(root, X[i], L, R);
            root = merge(merge(L, create(i)), R);
        }

        firstElement = true;
        printTreap(root);
        cout << "\n";
    }

    return 0;
}