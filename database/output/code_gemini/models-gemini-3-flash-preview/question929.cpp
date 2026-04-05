/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Pais das Folhas
 * Description: Given a tree description, list all nodes that have at least one leaf as a child.
 * A leaf is a node with no children. Root is node 0.
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

struct Node {
    int left;
    int right;
};

int main() {
    // Optimization for fast I/O in C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the number of nodes
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    // tree[i] stores the children of node i
    vector<Node> tree(n);
    // is_leaf[i] tracks if node i is a leaf (no children)
    vector<bool> is_leaf(n, false);

    for (int i = 0; i < n; ++i) {
        if (!(cin >> tree[i].left >> tree[i].right)) break;
        // According to the problem, a leaf has no children (indicated by -1)
        if (tree[i].left == -1 && tree[i].right == -1) {
            is_leaf[i] = true;
        }
    }

    // Iterate through nodes in ascending order to find parents of leaves
    // This naturally satisfies the requirement for an ordered list
    for (int i = 0; i < n; ++i) {
        bool has_leaf_child = false;

        // Check left child
        if (tree[i].left != -1) {
            if (tree[i].left >= 0 && tree[i].left < n && is_leaf[tree[i].left]) {
                has_leaf_child = true;
            }
        }
        
        // Check right child (only if left child wasn't a leaf)
        if (!has_leaf_child && tree[i].right != -1) {
            if (tree[i].right >= 0 && tree[i].right < n && is_leaf[tree[i].right]) {
                has_leaf_child = true;
            }
        }

        // If the node has at least one child that is a leaf, output its index
        if (has_leaf_child) {
            cout << i << "\n";
        }
    }

    return 0;
}