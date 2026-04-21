/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    int left;
    int right;
};

struct Item {
    int u;
    int level;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> tree[i].val >> tree[i].left >> tree[i].right)) break;
    }

    vector<int> min_vals;
    vector<int> max_vals;

    queue<Item> q;
    q.push({0, 0});

    while (!q.empty()) {
        Item curr = q.front();
        q.pop();

        int u = curr.u;
        int level = curr.level;

        if (u < 0 || u >= n) continue;

        if (level == (int)min_vals.size()) {
            min_vals.push_back(tree[u].val);
            max_vals.push_back(tree[u].val);
        } else {
            if (tree[u].val < min_vals[level]) min_vals[level] = tree[u].val;
            if (tree[u].val > max_vals[level]) max_vals[level] = tree[u].val;
        }

        if (tree[u].left != -1) {
            q.push({tree[u].left, level + 1});
        }
        if (tree[u].right != -1) {
            q.push({tree[u].right, level + 1});
        }
    }

    for (int i = 0; i < (int)min_vals.size(); ++i) {
        cout << "Nivel " << i + 1 << ": Maior = " << max_vals[i] << ", Menor = " << min_vals[i] << "\n";
    }

    return 0;
}