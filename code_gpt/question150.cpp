/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateP(int index, const vector<int> &nodes) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left >= nodes.size() && right >= nodes.size()) {
        return nodes[index];
    }
    
    int pl = (left < nodes.size()) ? calculateP(left, nodes) : 0;
    int pr = (right < nodes.size()) ? calculateP(right, nodes) : 0;
    
    return max(nodes[index] * pl, nodes[index] * pr);
}

int main() {
    int h;
    cin >> h;
    int n = (1 << h) - 1;
    vector<int> nodes(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    
    cout << calculateP(0, nodes) << endl;
    return 0;
}
