/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N1, N2;
    if (!(cin >> N1 >> N2)) return 0;

    vector<long long> oldList(N1);
    unordered_set<long long> oldSet;
    oldSet.reserve((size_t)N1 * 2 + 10);
    for (int i = 0; i < N1; i++) {
        cin >> oldList[i];
        oldSet.insert(oldList[i]);
    }

    vector<long long> seq;
    seq.reserve((size_t)N1 + N2 + 5);

    for (int i = 0; i < N1; i++) seq.push_back(oldList[i]);

    int newCount = 0;
    while (newCount < N2) {
        long long x;
        cin >> x;
        if (oldSet.find(x) == oldSet.end()) {
            oldSet.insert(x);
            seq.push_back(x);
            newCount++;
        }
    }

    int n = (int)seq.size();
    vector<long long> processed(n);

    for (int i = 0; i < n; i++) {
        if (i == 0) processed[i] = seq[i];
        else if (i == n - 1) processed[i] = seq[i] * seq[i - 1];
        else processed[i] = llabs(seq[i - 1] * seq[i] - seq[i + 1]);
    }

    vector<long long> allVals = processed;
    sort(allVals.begin(), allVals.end());

    unordered_set<long long> delSet;
    delSet.reserve((size_t)N1 * 2 + 10);
    for (auto v : oldList) delSet.insert(v);

    for (size_t i = 0; i < allVals.size(); i++) {
        long long v = allVals[i];
        if (delSet.find(v) != delSet.end()) cout << "DELETADO";
        else cout << v;
        if (i + 1 < allVals.size()) cout << ' ';
    }
    cout << '\n';
    return 0;
}