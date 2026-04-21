/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> leftChild(N, -1), rightChild(N, -1);
    for (int i = 0; i < N; i++) {
        cin >> leftChild[i] >> rightChild[i];
    }

    vector<char> isLeaf(N, 0);
    vector<char> hasLeft(N, 0), hasRight(N, 0);
    for (int i = 0; i < N; i++) {
        if (leftChild[i] != -1) hasLeft[i] = 1;
        if (rightChild[i] != -1) hasRight[i] = 1;
        if (leftChild[i] == -1 && rightChild[i] == -1) isLeaf[i] = 1;
    }

    vector<int> parents;
    for (int i = 0; i < N; i++) {
        int leafCount = 0;
        if (leftChild[i] != -1 && isLeaf[leftChild[i]]) leafCount++;
        if (rightChild[i] != -1 && isLeaf[rightChild[i]]) leafCount++;
        if (leafCount == 1 || leafCount == 2) parents.push_back(i);
    }

    sort(parents.begin(), parents.end());
    for (int x : parents) cout << x << "\n";
    return 0;
}