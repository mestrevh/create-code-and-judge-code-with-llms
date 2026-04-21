/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<long long>> lists;
    vector<long long> current;
    long long x;
    while (cin >> x) {
        current.push_back(x);
        if (x == 420) {
            lists.push_back(current);
            current.clear();
            if ((int)lists.size() == 3) break;
        }
    }

    sort(lists.begin(), lists.end(), [](const vector<long long>& a, const vector<long long>& b){
        return a < b;
    });

    for (int i = 0; i < 3; i++) {
        cout << lists[i].size();
        for (auto v : lists[i]) cout << " " << v;
        if (i < 2) cout << "\n";
    }
    return 0;
}