/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> data;
    int t;
    while (cin >> t && t != 0) {
        if (t == 1) {
            int Q;
            cin >> Q;
            vector<int> minutes(Q);
            for (int i = 0; i < Q; ++i) cin >> minutes[i];
            data.push_back(minutes);
            cout << data.size() << endl;
        } else if (t == 2) {
            int d;
            cin >> d;
            if (d >= 0 && d < data.size()) {
                cout << data[d].size() << endl;
                data.erase(data.begin() + d);
            }
        } else if (t == 3) {
            int i;
            cin >> i;
            int max_blinks = *max_element(data[i].begin(), data[i].end());
            cout << max_blinks << endl;
        } else if (t == 4) {
            int j;
            cin >> j;
            int max_blinks = 0;
            for (const auto& day : data) {
                if (j < day.size()) {
                    max_blinks = max(max_blinks, day[j]);
                }
            }
            cout << max_blinks << endl;
        }
    }
    return 0;
}
