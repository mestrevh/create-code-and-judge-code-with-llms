/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <tuple>

using namespace std;

struct Node {
    int value, level;
    unique_ptr<Node> left, right;

    Node(int v, int lvl) : value(v), level(lvl), left(nullptr), right(nullptr) {}
};

class BST {
public:
    unique_ptr<Node> root;
    int count;

    BST() : root(nullptr), count(0) {}

    tuple<int, bool> insert(int x) {
        return insertHelper(root, x, 0);
    }

    tuple<int, bool> insertHelper(unique_ptr<Node>& curr, int x, int lvl) {
        if (!curr) {
            curr = make_unique<Node>(x, lvl);
            count++;
            return {lvl, true};
        }
        if (x < curr->value) return insertHelper(curr->left, x, lvl + 1);
        if (x > curr->value) return insertHelper(curr->right, x, lvl + 1);
        return {curr->level, false};
    }

    tuple<int, bool> remove(int x) {
        return removeHelper(root, x);
    }

    tuple<int, bool> removeHelper(unique_ptr<Node>& curr, int x) {
        if (!curr) return {-1, false};

        if (x < curr->value) return removeHelper(curr->left, x);
        if (x > curr->value) return removeHelper(curr->right, x);

        int lvl = curr->level;
        if (!curr->left) {
            curr = move(curr->right);
        } else if (!curr->right) {
            curr = move(curr->left);
        } else {
            auto [successorVal, successorLvl] = findMin(curr->right);
            curr->value = successorVal;
            remove(successorVal);
        }
        count--;
        return {lvl, true};
    }

    tuple<int, int> findMin(unique_ptr<Node>& curr) {
        int lvl = 0;
        while (curr && curr->left) {
            curr = move(curr->left);
            lvl++;
        }
        return {curr->value, lvl};
    }

    int countGreater(int x) {
        return countGreaterHelper(root, x);
    }

    int countGreaterHelper(unique_ptr<Node>& curr, int x) {
        if (!curr) return 0;
        if (curr->value <= x) {
            return countGreaterHelper(curr->right, x);
        }
        return 1 + countGreaterHelper(curr->left, x) + countGreaterHelper(curr->right, x);
    }

    int kth(int k) {
        vector<int> sorted;
        inorder(root, sorted);
        return sorted[k - 1];
    }

    void inorder(unique_ptr<Node>& curr, vector<int>& result) {
        if (!curr) return;
        inorder(curr->left, result);
        result.push_back(curr->value);
        inorder(curr->right, result);
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        BST bst;
        vector<int> results;

        for (int i = 0; i < N; i++) {
            int C, X;
            cin >> C >> X;

            if (C == 1) {
                auto [level, inserted] = bst.insert(X);
                results.push_back(level);
            } else if (C == 2) {
                auto [level, removed] = bst.remove(X);
                results.push_back(level);
            } else if (C == 3) {
                results.push_back(bst.countGreater(X));
            } else if (C == 4) {
                results.push_back(bst.kth(X));
            }
        }

        for (int res : results) {
            cout << res << endl;
        }
        cout << endl;
    }

    return 0;
}
