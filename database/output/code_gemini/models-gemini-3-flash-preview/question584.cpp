/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    int height;
    int left, right;
};

Node tree[1200000];
int free_nodes[1200000];
int pool_top = 0;
int free_top = 0;

int alloc_node(int key) {
    int idx = (free_top > 0) ? free_nodes[--free_top] : ++pool_top;
    tree[idx].key = key;
    tree[idx].height = 1;
    tree[idx].left = 0;
    tree[idx].right = 0;
    return idx;
}

void dealloc_node(int idx) {
    free_nodes[free_top++] = idx;
}

int get_height(int idx) {
    return idx ? tree[idx].height : 0;
}

void update_height(int idx) {
    if (idx) {
        int lh = get_height(tree[idx].left);
        int rh = get_height(tree[idx].right);
        tree[idx].height = 1 + (lh > rh ? lh : rh);
    }
}

int insert(int idx, int key, int &h) {
    if (!idx) {
        h = 1;
        return alloc_node(key);
    }
    if (key < tree[idx].key) {
        tree[idx].left = insert(tree[idx].left, key, h);
    } else if (key > tree[idx].key) {
        tree[idx].right = insert(tree[idx].right, key, h);
    } else {
        h = tree[idx].height;
        return idx;
    }
    update_height(idx);
    return idx;
}

int remove(int idx, int key, int &h) {
    if (!idx) {
        h = 0;
        return 0;
    }
    if (key < tree[idx].key) {
        tree[idx].left = remove(tree[idx].left, key, h);
    } else if (key > tree[idx].key) {
        tree[idx].right = remove(tree[idx].right, key, h);
    } else {
        h = tree[idx].height;
        if (!tree[idx].left) {
            int next = tree[idx].right;
            dealloc_node(idx);
            return next;
        } else if (!tree[idx].right) {
            int next = tree[idx].left;
            dealloc_node(idx);
            return next;
        } else {
            int successor = tree[idx].right;
            while (tree[successor].left) successor = tree[successor].left;
            int successor_key = tree[successor].key;
            int dummy;
            tree[idx].right = remove(tree[idx].right, successor_key, dummy);
            tree[idx].key = successor_key;
        }
    }
    update_height(idx);
    return idx;
}

int query(int idx, int key) {
    while (idx) {
        if (key == tree[idx].key) return tree[idx].height;
        if (key < tree[idx].key) idx = tree[idx].left;
        else idx = tree[idx].right;
    }
    return 0;
}

void find_min_in_range(int idx, int l, int r, int &res, bool &found) {
    res = -1;
    found = false;
    while (idx) {
        if (tree[idx].key >= l) {
            if (tree[idx].key <= r) {
                res = tree[idx].key;
                found = true;
            }
            idx = tree[idx].left;
        } else {
            idx = tree[idx].right;
        }
    }
}

void find_max_in_range(int idx, int l, int r, int &res, bool &found) {
    res = -1;
    found = false;
    while (idx) {
        if (tree[idx].key <= r) {
            if (tree[idx].key >= l) {
                res = tree[idx].key;
                found = true;
            }
            idx = tree[idx].right;
        } else {
            idx = tree[idx].left;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M, seed, A, C;
    if (!(cin >> N >> M >> seed >> A >> C)) return 0;

    int root = 0;
    int dummy_h;
    long long current_X = seed;
    root = insert(root, (int)current_X, dummy_h);
    for (int i = 1; i < N; ++i) {
        current_X = (A * current_X + C) % M;
        if (current_X < 0) current_X += M;
        root = insert(root, (int)current_X, dummy_h);
    }

    string cmd;
    int seq = 0;
    while (cin >> cmd) {
        if (cmd == "ADD") {
            int k; cin >> k;
            int h;
            root = insert(root, k, h);
            cout << seq++ << " " << h << "\n";
        } else if (cmd == "DEL") {
            int k; cin >> k;
            int h;
            root = remove(root, k, h);
            cout << seq++ << " " << h << "\n";
        } else if (cmd == "QRY") {
            int k; cin >> k;
            cout << seq++ << " " << query(root, k) << "\n";
        } else if (cmd == "INT") {
            int l, r; cin >> l >> r;
            int mn, mx;
            bool found_mn, found_mx;
            find_min_in_range(root, l, r, mn, found_mn);
            cout << seq++;
            if (found_mn) {
                find_max_in_range(root, l, r, mx, found_mx);
                cout << " " << mn << " " << mx;
            }
            cout << "\n";
        }
    }

    return 0;
}