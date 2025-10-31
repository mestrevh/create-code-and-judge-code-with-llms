/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

set<int> possibleGroups;
vector<set<int>> parents;

void generateGroups(int index, set<int> currentGroups) {
    if (index == parents.size()) {
        possibleGroups.insert(currentGroups.begin(), currentGroups.end());
        return;
    }
    for (int antigen : parents[index]) {
        currentGroups.insert(antigen);
        generateGroups(index + 1, currentGroups);
        currentGroups.erase(antigen);
    }
    generateGroups(index + 1, currentGroups);
}

int main() {
    int N, Q;
    cin >> N >> Q;
    parents.resize(N);
    
    for (int i = 0; i < N; ++i) {
        int B;
        cin >> B;
        parents[i].resize(B);
        for (int j = 0; j < B; ++j) {
            cin >> parents[i][j];
        }
    }

    generateGroups(0, {});

    for (int i = 0; i < Q; ++i) {
        int B;
        cin >> B;
        set<int> query;
        for (int j = 0; j < B; ++j) {
            int C;
            cin >> C;
            query.insert(C);
        }
        cout << (query.size() == query.count(*query.begin()) && possibleGroups.count(*query.begin()) ? "Y" : "N") << endl;
    }

    return 0;
}
