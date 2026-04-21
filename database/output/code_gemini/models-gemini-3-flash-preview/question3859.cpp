/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    if (!(cin >> n1 >> n2)) return 0;

    set<ll> checklist;
    for (int i = 0; i < n1; ++i) {
        ll x;
        cin >> x;
        checklist.insert(x);
    }

    vector<ll> line;
    int count_new = 0;
    ll val;
    while (count_new < n2 && cin >> val) {
        line.push_back(val);
        if (checklist.find(val) == checklist.end()) {
            count_new++;
        }
    }

    int k = line.size();
    if (k == 0) return 0;

    vector<ll> p(k);
    p[0] = line[0];
    if (k > 1) {
        for (int i = 1; i < k - 1; ++i) {
            ll res = (ll)line[i] * line[i - 1] - line[i + 1];
            if (res < 0) res = -res;
            p[i] = res;
        }
        p[k - 1] = (ll)line[k - 1] * line[k - 2];
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < k; ++i) {
        if (checklist.find(p[i]) != checklist.end()) {
            cout << "DELETADO";
        } else {
            cout << p[i];
        }
        if (i < k - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}