/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    int min_val = -1;
    int max_val = -1;
    int total_count = 0;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "ADD") {
            int v;
            cin >> v;
            if (total_count == 0) {
                min_val = max_val = v;
            } else {
                if (v < min_val) min_val = v;
                if (v > max_val) max_val = v;
            }

            if (upper.empty() || v >= upper.top()) {
                upper.push(v);
            } else {
                lower.push(v);
            }

            if (upper.size() > lower.size() + 1) {
                lower.push(upper.top());
                upper.pop();
            } else if (lower.size() > upper.size()) {
                upper.push(lower.top());
                lower.pop();
            }

            total_count++;
            cout << min_val << " " << upper.top() << " " << max_val << "\n";
        } else if (cmd == "MIN") {
            if (total_count == 0) cout << "-1\n";
            else cout << min_val << "\n";
        } else if (cmd == "MAX") {
            if (total_count == 0) cout << "-1\n";
            else cout << max_val << "\n";
        } else if (cmd == "MED") {
            if (total_count == 0) cout << "-1\n";
            else cout << upper.top() << "\n";
        } else if (cmd == "RES") {
            cout << total_count << "\n";
            lower = priority_queue<int>();
            upper = priority_queue<int, vector<int>, greater<int>>();
            min_val = -1;
            max_val = -1;
            total_count = 0;
        }
    }

    return 0;
}