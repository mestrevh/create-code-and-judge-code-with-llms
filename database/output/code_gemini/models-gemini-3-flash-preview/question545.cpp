/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Using a pre-allocated pool for BST nodes to ensure performance and memory efficiency.
struct Node {
    int val;
    int l, r;
    int sz;
};

// 1.1 million nodes to accommodate initial N=10^6 plus up to 10^4 ADD operations.
Node tree[1100005];
int poolPtr = 0;

int newNode(int k) {
    int idx = poolPtr++;
    tree[idx].val = k;
    tree[idx].l = -1;
    tree[idx].r = -1;
    tree[idx].sz = 1;
    return idx;
}

inline int getSize(int t) {
    return (t == -1) ? 0 : tree[t].sz;
}

inline void updateSize(int t) {
    if (t != -1) {
        tree[t].sz = 1 + getSize(tree[t].l) + getSize(tree[t].r);
    }
}

// Standard BST addition with size updates for INT and SGE operations.
int add(int& t, int k) {
    if (t == -1) {
        t = newNode(k);
        return 1;
    }
    if (k == tree[t].val) return 0;
    int res;
    if (k < tree[t].val) res = add(tree[t].l, k);
    else res = add(tree[t].r, k);
    if (res) updateSize(t);
    return res;
}

// Helper to remove the minimum element of a subtree and return its value.
int deleteMin(int& t) {
    if (tree[t].l == -1) {
        int minVal = tree[t].val;
        t = tree[t].r;
        return minVal;
    }
    int minVal = deleteMin(tree[t].l);
    updateSize(t);
    return minVal;
}

// Standard BST removal with size updates.
int remove(int& t, int k) {
    if (t == -1) return 0;
    int res;
    if (k < tree[t].val) {
        res = remove(tree[t].l, k);
        if (res) updateSize(t);
        return res;
    } else if (k > tree[t].val) {
        res = remove(tree[t].r, k);
        if (res) updateSize(t);
        return res;
    } else {
        if (tree[t].l == -1) {
            t = tree[t].r;
        } else if (tree[t].r == -1) {
            t = tree[t].l;
        } else {
            // Replace with successor value and delete successor node
            tree[t].val = deleteMin(tree[t].r);
            updateSize(t);
        }
        return 1;
    }
}

// Counts elements less than or equal to k using subtree sizes in O(height).
int countLessEqual(int t, long long k) {
    if (t == -1) return 0;
    if ((long long)tree[t].val <= k) {
        return 1 + getSize(tree[t].l) + countLessEqual(tree[t].r, k);
    } else {
        return countLessEqual(tree[t].l, k);
    }
}

// Finds the k-th smallest element in the BST in O(height).
int findKth(int t, int k) {
    int leftSz = getSize(tree[t].l);
    if (k == leftSz + 1) return tree[t].val;
    if (k <= leftSz) return findKth(tree[t].l, k);
    return findKth(tree[t].r, k - leftSz - 1);
}

int main() {
    // Fast I/O optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long seedY, z, w, modY, seedX, modX;
    if (!(cin >> N >> seedY >> z >> w >> modY >> seedX >> modX)) return 0;

    // Pseudo-random sequence generation according to problem specifications.
    // Using vector to store X to build the initial tree structure.
    vector<int> X(N);
    long long curY = seedY;
    long long curX = seedX;
    X[0] = (int)curX;
    for (int i = 1; i < N; ++i) {
        long long nextY = (curY * z + w) % modY;
        long long nextX = curX + 1 + (curY % modX);
        X[i] = (int)nextX;
        curY = nextY;
        curX = nextX;
    }

    int bstRoot = -1;
    // Recursive closure for initial BST population following specific insertion order.
    auto bst_init_recursive = [&](auto self, int a, int b) -> void {
        if (a > b) return;
        int c = (a + b) / 2;
        add(bstRoot, X[c]);
        self(self, a, c - 1);
        self(self, c + 1, b);
    };

    bst_init_recursive(bst_init_recursive, 0, N - 1);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "ADD") {
            int k; cin >> k;
            cout << add(bstRoot, k) << "\n";
        } else if (cmd == "DEL") {
            int k; cin >> k;
            cout << remove(bstRoot, k) << "\n";
        } else if (cmd == "INT") {
            int a, b; cin >> a >> b;
            if (a > b) {
                cout << "0\n";
            } else {
                // [a, b] count is (elements <= b) minus (elements < a).
                // Use long long for offset logic to prevent underflow from INT_MIN.
                cout << countLessEqual(bstRoot, (long long)b) - countLessEqual(bstRoot, (long long)a - 1) << "\n";
            }
        } else if (cmd == "SGE") {
            int sz = getSize(bstRoot);
            if (sz < 2) {
                cout << "-1\n";
            } else {
                // The second largest element in a set of size sz is the (sz-1)-th smallest.
                cout << findKth(bstRoot, sz - 1) << "\n";
            }
        }
    }

    return 0;
}