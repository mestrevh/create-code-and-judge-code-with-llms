/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
};

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

int main() {
    int P, S;
    cin >> P >> S;
    vector<Interval> intervals(S);
    
    for (int i = 0; i < S; i++) {
        cin >> intervals[i].start >> intervals[i].end;
        if (intervals[i].start > intervals[i].end) {
            swap(intervals[i].start, intervals[i].end);
        }
    }
    
    sort(intervals.begin(), intervals.end(), compare);
    
    vector<Interval> merged;
    
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back().end < interval.start) {
            merged.push_back(interval);
        } else {
            merged.back().end = max(merged.back().end, interval.end);
        }
    }
    
    for (const auto& interval : merged) {
        cout << interval.start << " " << interval.end << endl;
    }
    cout << endl;
    
    return 0;
}
