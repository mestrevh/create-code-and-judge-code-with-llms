/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

struct Node {
    int dist;
    int height;
    Node *left, *right;
    Node(int d) : dist(d), height(1), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balance(Node* node) {
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* node, int dist) {
        if (!node) return new Node(dist);
        if (dist < node->dist)
            node->left = insert(node->left, dist);
        else if (dist > node->dist)
            node->right = insert(node->right, dist);
        else return node;
        node->height = max(height(node->left), height(node->right)) + 1;
        int balanceFactor = balance(node);
        if (balanceFactor > 1 && dist < node->left->dist)
            return rightRotate(node);
        if (balanceFactor < -1 && dist > node->right->dist)
            return leftRotate(node);
        if (balanceFactor > 1 && dist > node->left->dist) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balanceFactor < -1 && dist < node->right->dist) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    int countRemovals(Node*& node, int L, int R) {
        if (!node) return 0;
        if (node->dist < L) return countRemovals(node->right, L, R);
        if (node->dist > R) return countRemovals(node->left, L, R);
        int leftCount = countRemovals(node->left, L, R);
        int rightCount = countRemovals(node->right, L, R);
        delete node;
        node = nullptr;
        return 1 + leftCount + rightCount;
    }

    void insert(int dist) { root = insert(root, dist); }
    int remove(int L, int R) { return countRemovals(root, L, R); }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, seedD, A, C;
    cin >> N >> M >> seedD >> A >> C;
    
    vector<int> D(N);
    D[0] = seedD;
    for (int i = 1; i < N; i++)
        D[i] = (1LL * A * D[i - 1] + C) % M;

    vector<int> heights(N, 0);
    BST bst;
    auto partition = [&](int l, int r) -> int {
        if (r - l < 3) return l;
        int m0 = l, m1 = (l + r) / 2, m2 = r - 1;
        if (D[m0] > D[m1] && D[m0] > D[m2])
            return D[m1] > D[m2] ? m2 : m1;
        return D[m1] > D[m2] ? m0 : m1;
    };

    function<int(int, int)> buildTree = [&](int l, int r) -> int {
        if (l > r) return 0;
        int p = partition(l, r + 1);

        heights[p] = 1 + max(buildTree(l, p - 1), buildTree(p + 1, r));
        return heights[p];
    };

    int h = buildTree(0, N - 1);
    cout << 0 << ": " << h << endl;

    int Q;
    cin >> Q;
    set<int> distances;
    
    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        if (command == "ADD") {
            int dist;
            cin >> dist;
            if (distances.count(dist)) {
                cout << (i + 1) << ": 0" << endl;
            } else {
                bst.insert(dist);
                distances.insert(dist);
                cout << (i + 1) << ": 1" << endl;
            }
        } else if (command == "DEL") {
            int L, R;
            cin >> L >> R;
            cout << (i + 1) << ": " << bst.remove(L, R) << endl;
        }
    }
    return 0;
}
