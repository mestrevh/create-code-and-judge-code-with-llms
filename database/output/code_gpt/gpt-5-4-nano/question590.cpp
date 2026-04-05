/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct DualHeapMedian {
    priority_queue<long long> low;
    priority_queue<long long, vector<long long>, greater<long long>> high;

    void clear() {
        while (!low.empty()) low.pop();
        while (!high.empty()) high.pop();
    }

    int size() const { return (int)low.size() + (int)high.size(); }

    void rebalance() {
        if (low.size() > high.size() + 1) {
            high.push(low.top());
            low.pop();
        } else if (high.size() > low.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    void add(long long x) {
        if (low.empty() || x <= low.top()) low.push(x);
        else high.push(x);
        rebalance();
    }

    long long getMin() const {
        if (low.empty() && high.empty()) return -1;
        if (high.empty()) return low.top();
        return high.top();
    }

    long long getMax() const {
        if (low.empty() && high.empty()) return -1;
        if (low.empty()) return high.top();
        return low.top(); 
    }

    long long getMed() const {
        int n = size();
        if (n == 0) return -1;
        return low.top(); 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DualHeapMedian ds;
    long long v;
    string op;
    long long beforeRes = 0;

    while (cin >> op) {
        if (op == "ADD") {
            cin >> v;
            ds.add(v);
            cout << ds.getMin() << ' ' << ds.getMed() << ' ' << ds.getMax() << "\n";
        } else if (op == "MIN") {
            cout << ds.getMin() << "\n";
        } else if (op == "MAX") {
            cout << ds.getMax() << "\n";
        } else if (op == "MED") {
            cout << ds.getMed() << "\n";
        } else if (op == "RES") {
            beforeRes = ds.size();
            ds.clear();
            cout << beforeRes << "\n";
        }
    }
    return 0;
}