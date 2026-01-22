/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node {
    int left, right;
};

void findParentsWithLeaves(int index, const vector<Node>& tree, set<int>& parents) {
    if (index == -1) return;
    if (tree[index].left == -1 && tree[index].right == -1) return;
    
    bool hasLeftLeaf = tree[index].left != -1 && tree[tree[index].left].left == -1 && tree[tree[index].left].right == -1;
    bool hasRightLeaf = tree[index].right != -1 && tree[tree[index].right].left == -1 && tree[tree[index].right].right == -1;
    
    if (hasLeftLeaf || hasRightLeaf) {
        parents.insert(index);
    }
    findParentsWithLeaves(tree[index].left, tree, parents);
    findParentsWithLeaves(tree[index].right, tree, parents);
}

int main() {
    int N;
    cin >> N;
    vector<Node> tree(N);
    for (int i = 0; i < N; i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    
    set<int> parents;
    findParentsWithLeaves(0, tree, parents);
    
    for (int parent : parents) {
        cout << parent << endl;
    }
    
    return 0;
}
