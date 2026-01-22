/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Node {
    int value;
    int left;
    int right;
};

int main() {
    int N;
    cin >> N;
    vector<Node> tree(N);

    for (int i = 0; i < N; i++) {
        cin >> tree[i].value >> tree[i].left >> tree[i].right;
    }

    queue<pair<int, int>> q; // par: (índice do nó, nível)
    q.push({0, 1});
    vector<int> minValues, maxValues;

    while (!q.empty()) {
        int size = q.size();
        int minVal = numeric_limits<int>::max();
        int maxVal = numeric_limits<int>::min();

        for (int i = 0; i < size; i++) {
            auto [index, level] = q.front();
            q.pop();

            if (index != -1) {
                minVal = min(minVal, tree[index].value);
                maxVal = max(maxVal, tree[index].value);
                q.push({tree[index].left, level + 1});
                q.push({tree[index].right, level + 1});
            }
        }

        if (maxVal != numeric_limits<int>::min()) {
            maxValues.push_back(maxVal);
            minValues.push_back(minVal);
        }
    }

    for (int i = 0; i < minValues.size(); i++) {
        cout << "Nivel " << i + 1 << ": Maior = " << maxValues[i] << ", Menor = " << minValues[i] << endl;
    }

    return 0;
}
