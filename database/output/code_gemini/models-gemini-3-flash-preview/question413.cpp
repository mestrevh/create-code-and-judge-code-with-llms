/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        if (n == 1) {
            cout << "Discarded cards:\n";
            cout << "Remaining card: 1\n";
            continue;
        }

        deque<int> dq;
        for (int i = 1; i <= n; ++i) {
            dq.push_back(i);
        }

        vector<int> discarded;
        discarded.reserve(n - 1);

        while (dq.size() >= 2) {
            discarded.push_back(dq.front());
            dq.pop_front();
            int next_to_base = dq.front();
            dq.pop_front();
            dq.push_back(next_to_base);
        }

        cout << "Discarded cards:";
        for (int i = 0; i < (int)discarded.size(); ++i) {
            if (i == 0) cout << " ";
            else cout << ", ";
            cout << discarded[i];
        }
        cout << "\n";
        
        if (!dq.empty()) {
            cout << "Remaining card: " << dq.front() << "\n";
        }
    }

    return 0;
}