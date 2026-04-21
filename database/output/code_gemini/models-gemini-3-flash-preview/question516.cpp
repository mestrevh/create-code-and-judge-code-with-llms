/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

struct Node {
    int val;
    Node *l, *r, *p;
    Node() : val(0), l(nullptr), r(nullptr), p(nullptr) {}
    void init(int v, Node* pr) {
        val = v; p = pr; l = r = nullptr;
    }
};

Node pool[200005];
int pool_ptr;

Node* allocate(int v, Node* p) {
    pool[pool_ptr].init(v, p);
    return &pool[pool_ptr++];
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;

inline int get_level(Node* n) {
    int l = 0;
    while (n && n->p) {
        n = n->p;
        l++;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        if (!(cin >> N)) break;
        Node* root = nullptr;
        pool_ptr = 0;
        map<int, Node*> node_map;
        OST pb_tree;

        for (int i = 0; i < N; i++) {
            int C, X;
            cin >> C >> X;
            if (C == 1) {
                auto it = node_map.find(X);
                if (it != node_map.end()) {
                    cout << get_level(it->second) << "\n";
                } else {
                    if (!root) {
                        root = allocate(X, nullptr);
                        node_map[X] = root;
                        pb_tree.insert(X);
                        cout << "0\n";
                    } else {
                        Node* curr = root;
                        Node* parent = nullptr;
                        int level = 0;
                        while (curr) {
                            parent = curr;
                            if (X < curr->val) curr = curr->l;
                            else curr = curr->r;
                            level++;
                        }
                        Node* newNode = allocate(X, parent);
                        if (X < parent->val) parent->l = newNode;
                        else parent->r = newNode;
                        node_map[X] = newNode;
                        pb_tree.insert(X);
                        cout << level << "\n";
                    }
                }
            } else if (C == 2) {
                auto it = node_map.find(X);
                if (it == node_map.end()) {
                    cout << "-1\n";
                } else {
                    Node* z = it->second;
                    cout << get_level(z) << "\n";
                    pb_tree.erase(X);
                    node_map.erase(it);

                    if (!z->l || !z->r) {
                        Node* child = z->l ? z->l : z->r;
                        if (!z->p) {
                            root = child;
                            if (root) root->p = nullptr;
                        } else {
                            if (z == z->p->l) z->p->l = child;
                            else z->p->r = child;
                            if (child) child->p = z->p;
                        }
                    } else {
                        Node* s = z->r;
                        while (s->l) s = s->l;
                        int s_val = s->val;
                        Node* s_child = s->r;
                        if (s == s->p->l) s->p->l = s_child;
                        else s->p->r = s_child;
                        if (s_child) s_child->p = s->p;
                        z->val = s_val;
                        node_map[s_val] = z;
                    }
                }
            } else if (C == 3) {
                cout << pb_tree.size() - pb_tree.order_of_key(X + 1) << "\n";
            } else if (C == 4) {
                if (X >= 1 && X <= (int)pb_tree.size()) {
                    cout << *pb_tree.find_by_order(X - 1) << "\n";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}

