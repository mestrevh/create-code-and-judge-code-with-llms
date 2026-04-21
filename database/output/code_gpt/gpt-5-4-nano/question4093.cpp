/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static vector<int> parseArray(const string& s) {
    vector<int> a;
    string cur;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if ((c >= '0' && c <= '9') || c == '-' || c == '+') {
            cur.push_back(c);
        } else {
            if (!cur.empty()) {
                a.push_back(stoi(cur));
                cur.clear();
            }
        }
    }
    if (!cur.empty()) a.push_back(stoi(cur));
    return a;
}

static int bsRec(const vector<int>& A, int k, int l, int r, vector<int>& visited) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    visited.push_back(mid + 1);
    if (A[mid] == k) return mid + 1;
    if (A[mid] > k) return bsRec(A, k, l, mid - 1, visited);
    return bsRec(A, k, mid + 1, r, visited);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    if (!(cin >> k >> n)) return 0;

    string line;
    getline(cin, line);
    getline(cin, line);

    vector<int> A = parseArray(line);

    if ((int)A.size() != n) {
        while ((int)A.size() < n) {
            if (!getline(cin, line)) break;
            vector<int> extra = parseArray(line);
            A.insert(A.end(), extra.begin(), extra.end());
        }
        if ((int)A.size() > n) A.resize(n);
    }

    vector<int> visited;
    int pos = bsRec(A, k, 0, (int)A.size() - 1, visited);

    vector<int> consultValues;
    for (int idx1 : visited) {
        int idx0 = idx1 - 1;
        if (idx0 >= 0 && idx0 < (int)A.size()) consultValues.push_back(A[idx0]);
    }

    auto printArrayOnce = [&]() {
        cout << '[';
        for (int i = 0; i < (int)A.size(); i++) {
            if (i) cout << ", ";
            cout << A[i];
        }
        cout << "]  ---->  ";
    };

    for (int t = 0; t < (int)visited.size(); t++) {
        printArrayOnce();
        cout << consultValues[t] << "\n";
    }

    printArrayOnce();
    cout << (pos == -1 ? -1 : pos) << "\n";
    return 0;
}