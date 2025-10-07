/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<pair<int, int>> intervals(n);
        for (int i = 0; i < n; ++i) {
            cin >> intervals[i].first >> intervals[i].second;
        }
        sort(intervals.begin(), intervals.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        int count = 0, last = -1;
        for (const auto& interval : intervals) {
            if (interval.first > last) {
                count++;
                last = interval.second;
            }
        }
        cout << count << endl;
    }
    return 0;
}
