/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    double start;
    double end;
};

bool compareEnd(Interval a, Interval b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    sort(intervals.begin(), intervals.end(), compareEnd);

    int maxCount = 0, currentCount = 0;
    double currentEnd = -1e9;

    for (const auto& interval : intervals) {
        if (interval.start < currentEnd) {
            currentCount++;
            currentEnd = max(currentEnd, interval.end);
        } else {
            currentCount = 1;
            currentEnd = interval.end;
        }
        maxCount = max(maxCount, currentCount);
    }

    cout << maxCount << endl;
    return 0;
}
